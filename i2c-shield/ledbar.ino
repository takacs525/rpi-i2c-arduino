
void SetupLEDbar() {
  pinMode(LEDBAR_LATCH_PIN, OUTPUT);
  pinMode(LEDBAR_CLOCK_PIN, OUTPUT);
  pinMode(LEDBAR_DATA_PIN, OUTPUT);

  LEDbar(0);
}

//-------------------------------------------------------------------------------

void LEDpercent(int per) {
  int bar = map(per, 0, 100, 0, LEDBAR_BARS);
  LEDbar(bar);
  
}

void LEDbar(int bar) {
  int numberToDisplay = 0xFFFF >> (LEDBAR_BARS - bar);
     
  digitalWrite(LEDBAR_LATCH_PIN, LOW);

  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, (numberToDisplay >> 8));  
  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, numberToDisplay);  

  digitalWrite(LEDBAR_LATCH_PIN, HIGH);  
}


