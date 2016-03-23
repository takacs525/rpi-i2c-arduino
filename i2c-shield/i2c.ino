
void SetupI2C() {
  Wire.begin(I2C_ADDRESS);                // join i2c bus with address
  Wire.onRequest(requestEvent);           // register event
  Wire.onReceive(receiveEvent);           // register event

  pinMode(I2C_IRQ_PIN, OUTPUT);
  digitalWrite(I2C_IRQ_PIN, LOW);  
}

//-------------------------------------------------------------------------------

void receiveEvent(int howMany) {
  Serial.print("Command: ");
  
  byte command = Wire.read();
  byte object = Wire.read();
  byte state = Wire.read();

  if (command == CMD_LED) {
    Serial.println("LED");
    Serial.print("  Object: ");
    if ( object == 1 || object == 2) {
      Serial.println(object);

      int led;
      if ( object == 1) {
        led = LED1_PIN;
      } else {
        led = LED2_PIN;
      }
      
      Serial.print("  State: ");
      if (state == 1) {
        Serial.println("ON");
        digitalWrite(led, HIGH);
      } else {
        Serial.println("OFF");
        digitalWrite(led, LOW);
      }
    } else {
      Serial.println("INVALID");
    }
  }

  if (command == CMD_LEDBAR) {
    Serial.println("LEDbar");
    Serial.print("  Object: ");
    if ( object == 1) {
      Serial.println(object);
      
      Serial.print("  State: ");
      Serial.println(state);
      LEDpercent(state);
      
    } else {
      Serial.println("INVALID");
    }
  }


  if (command == CMD_TONE) {
    lastCommand = command;
    lastObject = object;
    Serial.println("TONE");
    Serial.print("  Object: ");    
    if (object == 0x01) {
      Serial.println("Beep");
    } else {
      Serial.println("Play");
    }
  }

  if (command == CMD_TEST) {
    lastCommand = command;
    Serial.println("TEST");
  }

  if (command == CMD_GETSTATUS) {
    Serial.println("Send status");
    lastCommand = CMD_GETSTATUS;
  }

  if (command == CMD_GETBATTERY) {
    Serial.println("Send battery");
    lastCommand = CMD_GETBATTERY;
  }

  if (command == CMD_GETRFID) {
    Serial.println("Send RFID");
    lastCommand = CMD_GETRFID;
  }


  Serial.println();  
}

void requestEvent() {
  Serial.println("Request received");   
  Serial.print("LastCommand: ");
  Serial.print(lastCommand);
  Serial.println();

  if (lastCommand == CMD_GETSTATUS) {
    Wire.write(1);
    lastCommand = NONE;
  }

  if (lastCommand == CMD_GETBATTERY) {
    Wire.write(BatteryPercentage());
    lastCommand = NONE;
  }

  if (lastCommand == CMD_GETRFID) {
    Wire.write(lastRFID, 4);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(I2C_IRQ_PIN, LOW);  
    lastRFID[0] = 0;
    lastRFID[1] = 0;
    lastRFID[2] = 0;
    lastRFID[3] = 0;
    lastCommand = NONE;
  }
}



