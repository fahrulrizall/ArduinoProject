#include <MIDI.h>
#include "Controller.h"


MIDI_CREATE_DEFAULT_INSTANCE();

//---How many buttons are connected to a multiplexer?---------
byte NUMBER_MUX_BUTTONS = 92;
//---How many potentiometers are connected to a multiplexer?--
byte NUMBER_MUX_POTS = 47;


Mux M6(6, 16, false); //Digital multiplexer on Arduino pin 6
Mux M7(7, 16, false); //Digital multiplexer on Arduino pin 7
Mux M8(8, 16, false); //Digital multiplexer on Arduino pin 8
Mux M9(9, 16, false); //Digital multiplexer on Arduino pin 9
Mux M10(10, 16, false); //Digital multiplexer on Arduino pin 10
Mux M11(11, 16, false); //Digital multiplexer on Arduino pin 11
Mux M12(12, 16, false); //Digital multiplexer on Arduino pin 12

Mux M0(A0, 16, true); //Analog multiplexer on Arduino analog pin A0
Mux M1(A1, 16, true); //Analog multiplexer on Arduino analog pin A1
Mux M2(A2, 16, true); //Analog multiplexer on Arduino analog pin A2
Mux M3(A3, 16, true); //Analog multiplexer on Arduino analog pin A3
 

//***DEFINE BUTTONS CONNECTED TO MULTIPLEXER*************************
//Button::Button(Mux mux, byte muxpin, byte command, byte value, byte channel, byte debounce)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **

// MUX M6
Button MBU0(M6, 0, 0, 0, 1, 5);
Button MBU1(M6, 1, 0, 1, 1, 5);
Button MBU2(M6, 2, 0, 2, 1, 5);
Button MBU3(M6, 3, 0, 3, 1, 5);
Button MBU4(M6, 4, 0, 4, 1, 5);
Button MBU5(M6, 5, 0, 5, 1, 5);
Button MBU6(M6, 6, 0, 6, 1, 5);
Button MBU7(M6, 7, 0, 7, 1, 5);
Button MBU8(M6, 8, 0, 8, 1, 5);
Button MBU9(M6, 9, 0, 9, 1, 5);
Button MBU10(M6, 10, 0, 10, 1, 5);
Button MBU11(M6, 11, 0, 11, 1, 5);
Button MBU12(M6, 12, 0, 12, 1, 5);
Button MBU13(M6, 13, 0, 13, 1, 5);
Button MBU14(M6, 14, 0, 14, 1, 5);
Button MBU15(M6, 15, 0, 15, 1, 5);

//MUX M7
Button MBU16(M7, 0, 0, 16, 1, 5);
Button MBU17(M7, 1, 0, 17, 1, 5);
Button MBU18(M7, 2, 0, 18, 1, 5);
Button MBU19(M7, 3, 0, 19, 1, 5);
Button MBU20(M7, 4, 0, 20, 1, 5);
Button MBU21(M7, 5, 0, 21, 1, 5);
Button MBU22(M7, 6, 0, 22, 1, 5);
Button MBU23(M7, 7, 0, 23, 1, 5);
Button MBU24(M7, 8, 0, 24, 1, 5);
Button MBU25(M7, 9, 0, 25, 1, 5);
Button MBU26(M7, 10, 0, 26, 1, 5);
Button MBU27(M7, 11, 0, 27, 1, 5);
Button MBU28(M7, 12, 0, 28, 1, 5);
Button MBU29(M7, 13, 0, 29, 1, 5);
Button MBU30(M7, 14, 0, 30, 1, 5);
Button MBU31(M7, 15, 0, 31, 1, 5);

//MUX M8
Button MBU32(M8, 0, 0, 32, 1, 5);
Button MBU33(M8, 1, 0, 33, 1, 5);
Button MBU34(M8, 2, 0, 34, 1, 5);
Button MBU35(M8, 3, 0, 35, 1, 5);
Button MBU36(M8, 4, 0, 36, 1, 5);
Button MBU37(M8, 5, 0, 37, 1, 5);
Button MBU38(M8, 6, 0, 38, 1, 5);
Button MBU39(M8, 7, 0, 39, 1, 5);
Button MBU40(M8, 8, 0, 40, 1, 5);
Button MBU41(M8, 9, 0, 41, 1, 5);
Button MBU42(M8, 10, 0, 42, 1, 5);
Button MBU43(M8, 11, 0, 43, 1, 5);
Button MBU44(M8, 12, 0, 44, 1, 5);
Button MBU45(M8, 13, 0, 45, 1, 5);
Button MBU46(M8, 14, 0, 46, 1, 5);
Button MBU47(M8, 15, 0, 47, 1, 5);


//MUX M9
Button MBU48(M9, 0, 0, 48, 1, 5);
Button MBU49(M9, 1, 0, 49, 1, 5);
Button MBU50(M9, 2, 0, 50, 1, 5);
Button MBU51(M9, 3, 0, 51, 1, 5);
Button MBU52(M9, 4, 0, 52, 1, 5);
Button MBU53(M9, 5, 0, 53, 1, 5);
Button MBU54(M9, 6, 0, 54, 1, 5);
Button MBU55(M9, 7, 0, 55, 1, 5);
Button MBU56(M9, 8, 0, 56, 1, 5);
Button MBU57(M9, 9, 0, 57, 1, 5);
Button MBU58(M9, 10, 0, 58, 1, 5);
Button MBU59(M9, 11, 0, 59, 1, 5);
Button MBU60(M9, 12, 0, 60, 1, 5);
Button MBU61(M9, 13, 0, 61, 1, 5);
Button MBU62(M9, 14, 0, 62, 1, 5);
Button MBU63(M9, 15, 0, 63, 1, 5);

//MUX M10
Button MBU64(M10, 0, 0, 64, 1, 5);
Button MBU65(M10, 1, 0, 65, 1, 5);
Button MBU66(M10, 2, 0, 66, 1, 5);
Button MBU67(M10, 3, 0, 67, 1, 5);
Button MBU68(M10, 4, 0, 68, 1, 5);
Button MBU69(M10, 5, 0, 69, 1, 5);
Button MBU70(M10, 6, 0, 70, 1, 5);
Button MBU71(M10, 7, 0, 71, 1, 5);
Button MBU72(M10, 8, 0, 72, 1, 5);
Button MBU73(M10, 9, 0, 73, 1, 5);
Button MBU74(M10, 10, 0, 74, 1, 5);
Button MBU75(M10, 11, 0, 75, 1, 5);
Button MBU76(M10, 12, 0, 76, 1, 5);
Button MBU77(M10, 13, 0, 77, 1, 5);
Button MBU78(M10, 14, 0, 78, 1, 5);
Button MBU79(M10, 15, 0, 79, 1, 5);

//MUX M11
Button MBU80(M11, 0, 0, 80, 1, 5);
Button MBU81(M11, 1, 0, 81, 1, 5);
Button MBU82(M11, 2, 0, 82, 1, 5);
Button MBU83(M11, 3, 0, 83, 1, 5);
Button MBU84(M11, 4, 0, 84, 1, 5);
Button MBU85(M11, 5, 0, 85, 1, 5);
Button MBU86(M11, 6, 0, 85, 1, 5);
Button MBU87(M11, 7, 0, 87, 1, 5);
Button MBU88(M11, 8, 0, 88, 1, 5);
Button MBU89(M11, 9, 0, 89, 1, 5);
Button MBU90(M11, 10, 0, 90, 1, 5);
Button MBU91(M11, 11, 0, 91, 1, 5);
Button MBU92(M11, 12, 0, 92, 1, 5);
Button MBU93(M11, 13, 0, 93, 1, 5);
Button MBU94(M11, 14, 0, 94, 1, 5);
Button MBU95(M11, 15, 0, 95, 1, 5);


//MUX M12
Button MBU96(M12, 0, 0, 96, 1, 5);
Button MBU97(M12, 1, 0, 97, 1, 5);
Button MBU98(M12, 2, 0, 98, 1, 5);
Button MBU99(M12, 3, 0, 99, 1, 5);
Button MBU100(M12, 4, 0, 100, 1, 5);
Button MBU101(M12, 5, 0, 101, 1, 5);
Button MBU102(M12, 6, 0, 102, 1, 5);
Button MBU103(M12, 7, 0, 103, 1, 5);
Button MBU104(M12, 8, 0, 104, 1, 5);
Button MBU105(M12, 9, 0, 105, 1, 5);
Button MBU106(M12, 10, 0, 106, 1, 5);
Button MBU107(M12, 11, 0, 107, 1, 5);
Button MBU108(M12, 12, 0, 108, 1, 5);
Button MBU109(M12, 13, 0, 109, 1, 5);
Button MBU110(M12, 14, 0, 110, 1, 5);
Button MBU111(M12, 15, 0, 111, 1, 5);

//*******************************************************************
////Add multiplexed buttons used to array below like this->  Button *MUXBUTTONS[] {&MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6.....};
Button *MUXBUTTONS[] 
{
  &MBU0, &MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6, &MBU7, &MBU8, &MBU9, &MBU10, &MBU11, &MBU12, &MBU13, &MBU14, &MBU15,
  &MBU16, &MBU17, &MBU18, &MBU19, &MBU20, &MBU21, &MBU22, &MBU23, &MBU24, &MBU25, &MBU26, &MBU27, &MBU28, &MBU29, &MBU30, &MBU31,
  &MBU32, &MBU33, &MBU34, &MBU35, &MBU36, &MBU37, &MBU38, &MBU39, &MBU40, &MBU41, &MBU42, &MBU43, &MBU44, &MBU45, &MBU46, &MBU47,
  &MBU48, &MBU49, &MBU50, &MBU51, &MBU52, &MBU53, &MBU54, &MBU55, &MBU56, &MBU57, &MBU58, &MBU59, &MBU60, &MBU61, &MBU62, &MBU63,
  &MBU64, &MBU65, &MBU66, &MBU67, &MBU68, &MBU69, &MBU70, &MBU71, &MBU72, &MBU73, &MBU74, &MBU75, &MBU76, &MBU77, &MBU78, &MBU79,
  &MBU80, &MBU81, &MBU82, &MBU83, &MBU84, &MBU85, &MBU86, &MBU87, &MBU88, &MBU89, &MBU90, &MBU91, &MBU92, &MBU93, &MBU94, &MBU95,
  &MBU96, &MBU97, &MBU98, &MBU99, &MBU100, &MBU101, &MBU102, &MBU103, &MBU104, &MBU105, &MBU106, &MBU107, &MBU108, &MBU109, &MBU110, &MBU111,
};



//***DEFINE POTENTIOMETERS CONNECTED TO MULTIPLEXER*******************
//Pot::Pot(Mux mux, byte muxpin, byte command, byte control, byte channel)
//**Command parameter is for future use**

// M0
Pot MPO0(M0, 0, 0, 0, 1);
Pot MPO1(M0, 0, 0, 1, 1);
Pot MPO2(M0, 1, 0, 2, 1);
Pot MPO3(M0, 2, 0, 3, 1);
Pot MPO4(M0, 3, 0, 4, 1);
Pot MPO5(M0, 4, 0, 5, 1);
Pot MPO6(M0, 5, 0, 6, 1);
Pot MPO7(M0, 6, 0, 7, 1);
Pot MPO8(M0, 7, 0, 8, 1);
Pot MPO9(M0, 8, 0, 9, 1);
Pot MPO10(M0, 9, 0, 10, 1);
Pot MPO11(M0, 10, 0, 11, 1);
Pot MPO12(M0, 11, 0, 12, 1);
Pot MPO13(M0, 12, 0, 13, 1);
Pot MPO14(M0, 13, 0, 14, 1);
Pot MPO15(M0, 14, 0, 15, 1);

// M1
Pot MPO16(M1, 0, 0, 16, 1);
Pot MPO17(M1, 0, 0, 17, 1);
Pot MPO18(M1, 1, 0, 18, 1);
Pot MPO19(M1, 2, 0, 19, 1);
Pot MPO20(M1, 3, 0, 20, 1);
Pot MPO21(M1, 4, 0, 21, 1);
Pot MPO22(M1, 5, 0, 22, 1);
Pot MPO23(M1, 6, 0, 23, 1);
Pot MPO24(M1, 7, 0, 24, 1);
Pot MPO25(M1, 8, 0, 25, 1);
Pot MPO26(M1, 9, 0, 26, 1);
Pot MPO27(M1, 10, 0, 27, 1);
Pot MPO28(M1, 11, 0, 28, 1);
Pot MPO29(M1, 12, 0, 29, 1);
Pot MPO30(M1, 13, 0, 30, 1);
Pot MPO31(M1, 14, 0, 31, 1);


// M2
Pot MPO32(M2, 0, 0, 32, 1);
Pot MPO33(M2, 0, 0, 33, 1);
Pot MPO34(M2, 1, 0, 34, 1);
Pot MPO35(M2, 2, 0, 35, 1);
Pot MPO36(M2, 3, 0, 36, 1);
Pot MPO37(M2, 4, 0, 37, 1);
Pot MPO38(M2, 5, 0, 38, 1);
Pot MPO39(M2, 6, 0, 39, 1);
Pot MPO40(M2, 7, 0, 40, 1);
Pot MPO41(M2, 8, 0, 41, 1);
Pot MPO42(M2, 9, 0, 42, 1);
Pot MPO43(M2, 10, 0, 43, 1);
Pot MPO44(M2, 11, 0, 44, 1);
Pot MPO45(M2, 12, 0, 45, 1);
Pot MPO46(M2, 13, 0, 46, 1);
Pot MPO47(M2, 14, 0, 47, 1);

// M3
Pot MPO48(M3, 0, 0, 48, 1);
Pot MPO49(M3, 0, 0, 49, 1);
Pot MPO50(M3, 1, 0, 50, 1);
Pot MPO51(M3, 2, 0, 51, 1);
Pot MPO52(M3, 3, 0, 52, 1);
Pot MPO53(M3, 4, 0, 53, 1);
Pot MPO54(M3, 5, 0, 54, 1);
Pot MPO55(M3, 6, 0, 55, 1);
Pot MPO56(M3, 7, 0, 56, 1);
Pot MPO57(M3, 8, 0, 57, 1);
Pot MPO58(M3, 9, 0, 58, 1);
Pot MPO59(M3, 10, 0, 59, 1);
Pot MPO60(M3, 11, 0, 60, 1);
Pot MPO61(M3, 12, 0, 61, 1);
Pot MPO62(M3, 13, 0, 62, 1);
Pot MPO63(M3, 14, 0, 63, 1);
//******************************************************************
//Add multiplexed pots used to array below like this->  Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6.....};
Pot *MUXPOTS[] {
  &MPO0, &MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MPO10, &MPO11, &MPO12, &MPO13, &MPO14, &MPO15,
  &MPO16, &MPO17, &MPO18, &MPO19, &MPO20, &MPO21, &MPO22, &MPO23, &MPO24, &MPO25, &MPO26, &MPO27, &MPO28, &MPO29, &MPO30, &MPO31,
  &MPO32, &MPO33, &MPO34, &MPO35, &MPO36, &MPO37, &MPO38, &MPO39, &MPO40, &MPO41, &MPO42, &MPO43, &MPO44, &MPO45, &MPO46, &MPO47,
  &MPO48, &MPO49, &MPO50, &MPO51, &MPO52, &MPO53, &MPO54, &MPO55, &MPO56, &MPO57, &MPO58, &MPO59, &MPO60, &MPO61, &MPO62, &MPO63,
  };
//*******************************************************************


void setup() {
  
  //pinMode (tombol,INPUT);
  //digitalWrite (tombol,HIGH);
  Serial.begin(9600);
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  updateMuxButtons();
  updateMuxPots();
}


void updateMuxButtons() {

  // Cycle through Mux Button array
  for (int i = 0; i < NUMBER_MUX_BUTTONS; i = i + 1) {

    MUXBUTTONS[i]->muxUpdate();
    byte message = MUXBUTTONS[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (MUXBUTTONS[i]->Bcommand) {
        case 0: //Note
          MIDI.sendNoteOn(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
          break;
        case 1: //CC
          MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
          break;
        case 2: //Toggle
          if (MUXBUTTONS[i]->Btoggle == 0) {
            MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 127, MUXBUTTONS[i]->Bchannel);
            MUXBUTTONS[i]->Btoggle = 1;
          }
          else if (MUXBUTTONS[i]->Btoggle == 1) {
            MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
            MUXBUTTONS[i]->Btoggle = 0;
          }
          break;
      }
    }
    //  Button is not pressed
    if (message == 1) {
      switch (MUXBUTTONS[i]->Bcommand) {
        case 0:
          MIDI.sendNoteOff(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
          break;
        case 1:
          MIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 0, MUXBUTTONS[i]->Bchannel);
          break;
      }
    }
  }
}


void updateMuxPots() {
  for (int i = 0; i < NUMBER_MUX_POTS; i = i + 1) {
    MUXPOTS[i]->muxUpdate();
    byte potmessage = MUXPOTS[i]->getValue();
    if (potmessage != 255) MIDI.sendControlChange(MUXPOTS[i]->Pcontrol, potmessage, MUXPOTS[i]->Pchannel);
  }
}
