
int BatteryRow()
{
  int sensorValue = analogRead(BATTERY_PIN);
  return sensorValue;
}
  
void BatteryPrintVoltage() {
  Serial.print("Current voltage: ");
  Serial.print((float)BatteryRow()/200);
  Serial.println(" V");
}

byte BatteryPercentage() {
  int per = map(BatteryRow(), 600, 840, 0, 100);
  if (per < 0) {
    per = 0;
  }
  if (per > 100) {
    per = 100;
  }
  return (byte)per;
}

