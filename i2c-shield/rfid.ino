void SetupRFID() {
  SPI.begin();          // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  ShowReaderDetails();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID..."));
}

void ShowReaderDetails() {
  // Get the MFRC522 software version
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown)"));
  Serial.println("");
  // When 0x00 or 0xFF is returned, communication probably failed
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}

void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
      lastRFID[i] = buffer[i];
      Serial.print(buffer[i] < 0x10 ? " 0" : " ");
      Serial.print(buffer[i], HEX);
    }
    Serial.println();
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(I2C_IRQ_PIN, HIGH);
}

