
#include "./config.h"
#include "./i2c_cmd.h"

// for RFID
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance

// for i2c
#include <Wire.h>

// global variables
byte lastCommand = NONE;
byte lastObject = NONE;
byte lastRFID[4] = {0, 0, 0, 0};

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		  // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  SetupRFID();
  SetupI2C();
  SetupLEDbar();
}

void loop() {
  
  if (lastCommand == CMD_TONE) {
    if (lastObject == 0x01) {
      ToneBeep();
    } else {
      TonePlay();
    }
    lastCommand = NONE;
    lastObject = NONE;
  }

  if (lastCommand == CMD_TEST) {
    Test();
    lastCommand = NONE;
  }

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() ) {
    Serial.print(F("Card UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    ToneCard();
  }

  //delay(1000);  
}


