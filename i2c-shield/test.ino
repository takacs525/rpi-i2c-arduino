void Test() {
  for (int i=0; i < 5; i++){
    LEDpercent(100);
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    delay(1000);  

    LEDpercent(0);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    delay(1000); 
  } 
}
