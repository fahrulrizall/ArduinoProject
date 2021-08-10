#include <MIDI.h>
#include "Controller.h"


MIDI_CREATE_DEFAULT_INSTANCE();

//---How many buttons are connected to a multiplexer?---------
byte NUMBER_MUX_BUTTONS = 96;
//---How many potentiometers are connected to a multiplexer?--
byte NUMBER_MUX_POTS = 48;


Mux M1(6, 16, false); //Digital multiplexer on Arduino pin 6
Mux M2(7, 16, false); //Digital multiplexer on Arduino pin 7
Mux M3(8, 16, false); //Digital multiplexer on Arduino pin 8
Mux M4(9, 16, false); //Digital multiplexer on Arduino pin 9
Mux M5(10, 16, false); //Digital multiplexer on Arduino pin 9
Mux M6(11, 16, false); //Digital multiplexer on Arduino pin 9

Mux MA(A0, 16, true); //Analog multiplexer on Arduino analog pin A0
Mux MB(A1, 16, true); //Analog multiplexer on Arduino analog pin A1
Mux MC(A2, 16, true); //Analog multiplexer on Arduino analog pin A2

//***DEFINE BUTTONS CONNECTED TO MULTIPLEXER*************************
//Button::Button(Mux mux, byte muxpin, byte command, byte value, byte channel, byte debounce)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **
//M1
Button MBU1(M1, 0, 0, 70, 1, 5);
Button MBU2(M1, 1, 0, 71, 1, 5);
Button MBU3(M1, 2, 0, 72, 1, 5);
Button MBU4(M1, 3, 0, 73, 1, 5);
Button MBU5(M1, 4, 0, 74, 1, 5);
Button MBU6(M1, 5, 0, 75, 1, 5);
Button MBU7(M1, 6, 0, 76, 1, 5);
Button MBU8(M1, 7, 0, 77, 1, 5);
Button MBU9(M1, 8, 0, 78, 1, 5);
Button MBU10(M1, 9, 0, 79, 1, 5);
Button MBU11(M1, 10, 0, 80, 1, 5);
Button MBU12(M1, 11, 0, 81, 1, 5);
Button MBU13(M1, 12, 0, 82, 1, 5);
Button MBU14(M1, 13, 0, 83, 1, 5);
Button MBU15(M1, 13, 0, 84, 1, 5);
Button MBU16(M1, 13, 0, 85, 1, 5);

//M2
Button MAU1(M2, 0, 0, 74, 1, 5);
Button MAU2(M2, 1, 0, 75, 1, 5);
Button MAU3(M1, 2, 0, 72, 1, 5);
Button MAU4(M1, 3, 0, 73, 1, 5);
Button MAU5(M1, 4, 0, 74, 1, 5);
Button MAU6(M1, 5, 0, 75, 1, 5);
Button MAU7(M1, 6, 0, 76, 1, 5);
Button MAU8(M1, 7, 0, 77, 1, 5);
Button MAU9(M1, 8, 0, 78, 1, 5);
Button MAU10(M1, 9, 0, 79, 1, 5);
Button MAU11(M1, 10, 0, 80, 1, 5);
Button MAU12(M1, 11, 0, 81, 1, 5);
Button MAU13(M1, 12, 0, 82, 1, 5);
Button MAU14(M1, 13, 0, 83, 1, 5);
Button MAU15(M1, 13, 0, 84, 1, 5);
Button MAU16(M1, 13, 0, 85, 1, 5);

//M3
//Button MCU1(M3, 0, 0, 74, 1, 5);
//Button MCU2(M3, 1, 0, 75, 1, 5);
//Button MCU3(M3, 2, 0, 72, 1, 5);
//Button MCU4(M3, 3, 0, 73, 1, 5);
//Button MCU5(M3, 4, 0, 74, 1, 5);
//Button MCU6(M3, 5, 0, 75, 1, 5);
//Button MCU7(M3, 6, 0, 76, 1, 5);
//Button MCU8(M3, 7, 0, 77, 1, 5);
//Button MCU9(M3, 8, 0, 78, 1, 5);
//Button MCU10(M3, 9, 0, 79, 1, 5);
//Button MCU11(M3, 10, 0, 80, 1, 5);
//Button MCU12(M3, 11, 0, 81, 1, 5);
//Button MCU13(M3, 12, 0, 82, 1, 5);
//Button MCU14(M3, 13, 0, 83, 1, 5);
//Button MCU15(M3, 13, 0, 84, 1, 5);
//Button MCU16(M3, 13, 0, 85, 1, 5);

//M4
//Button MDU1(M4, 0, 0, 74, 1, 5);
//Button MDU2(M4, 1, 0, 75, 1, 5);
//Button MDU3(M4, 2, 0, 72, 1, 5);
//Button MDU4(M4, 3, 0, 73, 1, 5);
//Button MDU5(M4, 4, 0, 74, 1, 5);
//Button MDU6(M4, 5, 0, 75, 1, 5);
//Button MDU7(M4, 6, 0, 76, 1, 5);
//Button MDU8(M4, 7, 0, 77, 1, 5);
//Button MDU9(M4, 8, 0, 78, 1, 5);
//Button MDU10(M4, 9, 0, 79, 1, 5);
//Button MDU11(M4, 10, 0, 80, 1, 5);
//Button MDU12(M4, 11, 0, 81, 1, 5);
//Button MDU13(M4, 12, 0, 82, 1, 5);
//Button MDU14(M4, 13, 0, 83, 1, 5);
//Button MDU15(M4, 13, 0, 84, 1, 5);
//Button MDU16(M4, 13, 0, 85, 1, 5);

//M5
//Button MEU1(M5, 0, 0, 74, 1, 5);
//Button MEU2(M5, 1, 0, 75, 1, 5);
//Button MEU3(M5, 2, 0, 72, 1, 5);
//Button MEU4(M5, 3, 0, 73, 1, 5);
//Button MEU5(M5, 4, 0, 74, 1, 5);
//Button MEU6(M5, 5, 0, 75, 1, 5);
//Button MEU7(M5, 6, 0, 76, 1, 5);
//Button MEU8(M5, 7, 0, 77, 1, 5);
//Button MEU9(M5, 8, 0, 78, 1, 5);
//Button MEU10(M5, 9, 0, 79, 1, 5);
//Button MEU11(M5, 10, 0, 80, 1, 5);
//Button MEU12(M5, 11, 0, 81, 1, 5);
//Button MEU13(M5, 12, 0, 82, 1, 5);
//Button MEU14(M5, 13, 0, 83, 1, 5);
//Button MEU15(M5, 13, 0, 84, 1, 5);
//Button MEU16(M5, 13, 0, 85, 1, 5);


//M6
//Button MFU1(M6, 0, 0, 74, 1, 5);
//Button MFU2(M6, 1, 0, 75, 1, 5);
//Button MFU3(M6, 2, 0, 72, 1, 5);
//Button MFU4(M6, 3, 0, 73, 1, 5);
//Button MFU5(M6, 4, 0, 74, 1, 5);
//Button MFU6(M6, 5, 0, 75, 1, 5);
//Button MFU7(M6, 6, 0, 76, 1, 5);
//Button MFU8(M6, 7, 0, 77, 1, 5);
//Button MFU9(M6, 8, 0, 78, 1, 5);
//Button MFU10(M6, 9, 0, 79, 1, 5);
//Button MFU11(M6, 10, 0, 80, 1, 5);
//Button MFU12(M6, 11, 0, 81, 1, 5);
//Button MFU13(M6, 12, 0, 82, 1, 5);
//Button MFU14(M6, 13, 0, 83, 1, 5);
//Button MFU15(M6, 13, 0, 84, 1, 5);
//Button MFU16(M6, 13, 0, 85, 1, 5);
//*******************************************************************
////Add multiplexed buttons used to array below like this->  Button *MUXBUTTONS[] {&MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6.....};
Button *MUXBUTTONS[] {
  &MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6, &MBU7, &MBU8, &MBU9, &MBU10, &MBU11, &MBU12, &MBU13, &MBU14, &MBU15, &MBU16, 
  &MAU1, &MAU2, &MAU3, &MAU4, &MAU5, &MAU6, &MAU7, &MAU8, &MAU9, &MAU10, &MAU11, &MAU12, &MAU13, &MAU14, &MAU15, &MAU16,
  //&MCU1, &MCU2, &MCU3, &MCU4, &MCU5, &MCU6, &MCU7, &MCU8, &MCU9, &MCU10, &MCU11, &MCU12, &MCU13, &MCU14, &MCU15, &MCU16,
  //&MDU1, &MDU2, &MDU3, &MDU4, &MDU5, &MDU6, &MDU7, &MDU8, &MDU9, &MDU10, &MDU11, &MDU12, &MDU13, &MDU14, &MDU15, &MDU16,
  //&MEU1, &MEU2, &MEU3, &MEU4, &MEU5, &MEU6, &MEU7, &MEU8, &MEU9, &MEU10, &MEU11, &MEU12, &MEU13, &MEU14, &MEU15, &MEU16,
  //&MFU1, &MFU2, &MFU3, &MFU4, &MFU5, &MFU6, &MFU7, &MFU8, &MFU9, &MFU10, &MFU11, &MFU12, &MFU13, &MFU14, &MFU15, &MFU16
  };


//***DEFINE POTENTIOMETERS CONNECTED TO MULTIPLEXER*******************
//Pot::Pot(Mux mux, byte muxpin, byte command, byte control, byte channel)
//**Command parameter is for future use**
//MA
//Pot MPO1(MA, 0, 0, 50, 1);
//Pot MPO2(MA, 1, 0, 55, 1);
//Pot MPO3(MA, 2, 0, 50, 1);
//Pot MPO4(MA, 3, 0, 55, 2);
//Pot MPO5(MA, 4, 0, 50, 1);
//Pot MPO6(MA, 5, 0, 55, 1);
//Pot MPO7(MA, 6, 0, 50, 1);
//Pot MPO8(MA, 7, 0, 55, 1);
//Pot MPO9(MA, 8, 0, 50, 1);
//Pot MPO10(MA, 9, 0, 55, 1);
//Pot MPO11(MA, 10, 0, 50, 1);
//Pot MPO12(MA, 11, 0, 55, 1);
//Pot MPO13(MA, 12, 0, 50, 1);
//Pot MPO14(MA, 13, 0, 55, 1);
//Pot MPO15(MA, 14, 0, 50, 1);
//Pot MPO16(MA, 15, 0, 55, 1);

//MB
//Pot MQO1(MB, 0, 0, 50, 1);
//Pot MQO2(MB, 1, 0, 55, 1);
//Pot MQO3(MB, 2, 0, 50, 1);
//Pot MQO4(MB, 3, 0, 55, 1);
//Pot MQO5(MB, 4, 0, 50, 1);
//Pot MQO6(MB, 5, 0, 55, 1);
//Pot MQO7(MB, 6, 0, 50, 1);
//Pot MQO8(MB, 7, 0, 55, 1);
//Pot MQO9(MB, 8, 0, 50, 1);
//Pot MQO10(MB, 9, 0, 55, 1);
//Pot MQO11(MB, 10, 0, 50, 1);
//Pot MQO12(MB, 11, 0, 55, 1);
//Pot MQO13(MB, 12, 0, 50, 1);
//Pot MQO14(MB, 13, 0, 55, 1);
//Pot MQO15(MB, 14, 0, 50, 1);
//Pot MQO16(MB, 15, 0, 55, 1);

//MC
//Pot MRO1(MC, 0, 0, 50, 1);
//Pot MRO2(MC, 1, 0, 55, 1);
//Pot MRO3(MC, 2, 0, 50, 1);
//Pot MRO4(MC, 3, 0, 55, 1);
//Pot MRO5(MC, 4, 0, 50, 1);
//Pot MRO6(MC, 5, 0, 55, 1);
//Pot MRO7(MC, 6, 0, 50, 1);
//Pot MRO8(MC, 7, 0, 55, 1);
//Pot MRO9(MC, 8, 0, 50, 1);
//Pot MRO10(MC, 9, 0, 55, 1);
//Pot MRO11(MC, 10, 0, 50, 1);
//Pot MRO12(MC, 11, 0, 55, 1);
//Pot MRO13(MC, 12, 0, 50, 1);
//Pot MRO14(MC, 13, 0, 55, 1);
//Pot MRO15(MC, 14, 0, 50, 1);
//Pot MRO16(MC, 15, 0, 55, 1);

//******************************************************************
//Add multiplexed pots used to array below like this->  Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6.....};
Pot *MUXPOTS[] {
  //&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MPO10, &MPO11, &MPO12, &MPO13, &MPO14, &MPO15, &MPO16,
  //&MQO1, &MQO2, &MQO3, &MQO4, &MQO5, &MQO6, &MQO7, &MQO8, &MQO9, &MQO10, &MQO11, &MQO12, &MQO13, &MQO14, &MQO15, &MQO16,
  //&MRO1, &MRO2, &MRO3, &MRO4, &MRO5, &MRO6, &MRO7, &MRO8, &MRO9, &MRO10, &MRO11, &MRO12, &MRO13, &MRO14, &MRO15, &MRO16
  };
//*******************************************************************


void setup() {
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  updateMuxButtons();
  updateMuxPots();
}

void changes(){
   for (int i = 0; i < NUMBER_MUX_BUTTONS; i = i + 1){
        if 
    
    } 
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
