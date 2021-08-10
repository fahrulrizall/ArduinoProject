#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
// ukuran buffer untuk menerima  permintaan HTTP
#define REQ_BUF_SZ   90
//Ukuran buffer yang menyimpan baris teks untuk terminator LCD + null
#define LCD_BUF_SZ   17
//Setup Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // mac address
IPAddress ip(192, 168, 10, 2);   // IP Address yang digunakan
EthernetServer server(80);       // Port yang digunakan
File webFile;                    // File halaman web pada SD Card
char HTTP_req[REQ_BUF_SZ] = {0}; // Permintaan HTTP buffer disimpan sebagai string null
char req_index = 0;              // index into HTTP_req buffer
char lcd_buf_1[LCD_BUF_SZ] = {0};// Indeks ke buffer HTTP_req
char lcd_buf_2[LCD_BUF_SZ] = {0};// Buffer untuk menyimpan teks 2 baris ke lcd
void setup()
{
    // Nonaktifkan chip Ethernet
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
  
    Serial.begin(115200);       // untuk debug
    lcd.begin(16, 2);
    // menampilkan teks di LCD
    lcd.print(F("Initializing"));
  
    // inisialisasi SD card
    Serial.println("Periksa SD Card...");
    if (!SD.begin(4)) {
        Serial.println("Gagal Koneksi SD card");
        lcd.print(F("SD Card Gagal!!"));
        return;    // gagal inisialisasi
    }
    Serial.println("Sukses Inisialisai SD card");
    // cek file index.htm
    if (!SD.exists("index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
        return;  // tidak menemukan file index.htm
    }
    Serial.println("File index.htm Ditemukan");
    Ethernet.begin(mac, ip);  // inisialisasi ethernet
    server.begin();         
    // selesai print IP adrress
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("IP Address WEB :"));
    lcd.setCursor(0, 1);
    lcd.print(ip);
}
void loop()
{
    EthernetClient client = server.available();  // mencoba mendapatkan Client
    if (client) {  // Kondisi Client
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // data client tersedia
                char c = client.read(); // Baca 1 byte (karakter) dari client
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // menyimpan HTTP request karakter
                    req_index++;
                }
                // baris terakhir permintaan klien kosong dan diakhiri dengan \ n
                //Menanggapi klien hanya setelah baris terakhir diterima
                if (c == '\n' && currentLineIsBlank) {
                    // kirim header tanggapan http standar
                    client.println("HTTP/1.1 200 OK");
                
                    if (StrContains(HTTP_req, "ajax_inputs")) {
                        // Kirim sisa header HTTP
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        // cetak teks yang diterima ke LCD jika ditemukan
                        if (GetLcdText(lcd_buf_1, lcd_buf_2, LCD_BUF_SZ)) {
                          /*lcd_buf_1 dan lcd_buf_2 sekarang berisi teks dari Halaman web dan
                          tampilkan teks yang diterima ke LCD*/
                          lcd.clear();
                          lcd.setCursor(0, 0);
                          lcd.print(lcd_buf_1);
                          lcd.setCursor(0, 1);
                          lcd.print(lcd_buf_2);
                        }
                    }
                    else {  //permintaan halaman web
                        // Kirim sisa header HTTP
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        // Kirim halaman web
                        webFile = SD.open("index.htm");        // open web page file
                        if (webFile) {
                            while(webFile.available()) {
                                client.write(webFile.read()); // send web page to client
                            }
                            webFile.close();
                        }
                    }
                   // reset buffer index dan semua elemen penyangga menjadi 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
              
                // setiap baris teks yang diterima dari klien berakhir dengan \ r \ n
                if (c == '\n') {           
                // karakter terakhir sesuai teks yang diterima
                // mulai baris baru dengan karakter berikutnya baca
                    currentLineIsBlank = true;
                }
                else if (c != '\r') {
                    // karakter teks diterima dari klien
                    currentLineIsBlank = false;
                }
            } // akhir if (client.available())
        } // akhir while (client.connected())
        delay(1);      // memberi waktu browser web untuk menerima data
        client.stop(); // mematikan Konkesi
    } // akhir if (client)
}
//Mendapatkan dua String untuk LCD dari permintaan HTTP GET yang masuk
boolean GetLcdText(char *line1, char *line2, int len)
{
  boolean got_text = false; 
  char *str_begin;           
  char *str_end;             
  int str_len = 0;
  int txt_index = 0;
  char *current_line;
  current_line = line1;

  str_begin = strstr(HTTP_req, "&L1=");
  for (int j = 0; j < 2; j++) {
    if (str_begin != NULL) {
      str_begin = strstr(str_begin, "="); 
      str_begin += 1;                     
      str_end = strstr(str_begin, "&");
      if (str_end != NULL) {
        str_end[0] = 0;  // Mengakhiri string
        str_len = strlen(str_begin);
        // salin string ke buffer dan ganti% 20 dengan spasi ''
        for (int i = 0; i < str_len; i++) {
          if (str_begin[i] != '%') {
            if (str_begin[i] == 0) {
              // akhir dari String
              break;
            }
            else {
              current_line[txt_index++] = str_begin[i];
              if (txt_index >= (len - 1)) {
                // Simpan string output dalam batas
                break;
              }
            }
          }
          else {
            // ganti% 20 dengan spasi
            if ((str_begin[i + 1] == '2') && (str_begin[i + 2] == '0')) {
              current_line[txt_index++] = ' ';
              i += 2;
              if (txt_index >= (len - 1)) {
                // simpan string output dalam batas
                break;
              }
            }
          }
        } // akhir untuk pengulangan i
        // Mengakhiri string
        current_line[txt_index] = 0;
        if (j == 0) {
        
        // dapatkan baris kedua
          str_begin = strstr(&str_end[1], "L2=");
          current_line = line2;
          txt_index = 0;
        }
        got_text = true;
      }
    }
  } // akhir untuk pengulangan j
  return got_text;
}
// set setiap elemen str ke 0 (hapus array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}
// mencari string sfind di string str
// kembali 1 jika string ditemukan
// kembali 0 jika string tidak ditemukan
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;
    len = strlen(str);
  
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }
    return 0; 
}
