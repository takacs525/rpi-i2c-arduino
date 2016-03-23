// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);           // start serial for output

  pinMode(2, INPUT);
  
}

byte x = 0;

void loop() {

  if (Serial.available() == 3) {
    byte command = Serial.read();
    byte commandByte;
    if (command == 'a')
    {
      commandByte = 0x81;
    }
    else if (command == 'b')
    {
      commandByte = 0x82;
    }
    else if (command == 'c')
    {
      commandByte = 0x83;
    }
    else if (command == 'd')
    {
      commandByte = 0x84;
    }
    else
    {
      commandByte = command - 48;
    }
    
    byte objectByte = Serial.read() - 48;
    byte stateByte = Serial.read() - 48;

    Serial.print("Send: ");
    Serial.print(commandByte, DEC);
    Serial.print(":");
    Serial.print(objectByte, DEC);
    Serial.print(":");
    Serial.print(stateByte, DEC);
    Serial.println();

    Wire.beginTransmission(66);  // transmit to device #42
    Wire.write(commandByte);     // sets command LED
    Wire.write(objectByte);      // sets LED number
    Wire.write(stateByte);       // sets ON
    Wire.endTransmission();      // stop transmitting


    if (commandByte == 1) {
      Get1Byte();
    }

    if (commandByte == 2) {
      Get1Byte();
    }

    if (commandByte == 3) {
      GetRFID();
    }
    
  Serial.println();
  }

  if (digitalRead(2) == 1) {
    Wire.beginTransmission(66);  // transmit to device #42
    Wire.write(3);     // sets command LED
    Wire.write(0);      // sets LED number
    Wire.write(0);       // sets ON
    Wire.endTransmission();      // stop transmitting
    
    GetRFID();
  }
  
  delay(10);
}

void Get1Byte() {
      Wire.requestFrom(66, 1);   // request 2 bytes from slave device #42
    
      byte byte1 = Wire.read();  
      Serial.println("Received: ");
      Serial.println(byte1);   // print the reading
}

void GetRFID() {
      Wire.requestFrom(66, 4);   // request 2 bytes from slave device #42
    
      byte byte1 = Wire.read();  
      byte byte2 = Wire.read(); 
      byte byte3 = Wire.read(); 
      byte byte4 = Wire.read(); 
                  
      Serial.println("Received: ");
      Serial.println(byte1);   // print the reading
      Serial.println(byte2);   // print the reading
      Serial.println(byte3);   // print the reading
      Serial.println(byte4);   // print the reading
}
