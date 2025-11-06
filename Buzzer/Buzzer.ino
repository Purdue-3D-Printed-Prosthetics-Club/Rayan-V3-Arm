void setup() {
  Serial.begin(9600);
}

void loop() {
  analogWrite(A3, 0);
  // Read the input on analog pin 0:
  int sensorValue = analogRead(A7);
  // Convert the analog reading (0–1023) to dutyCycle (0–255):
  // int dutyCycle = sensorValue * 255 / 1023;
  int threshold = map(sensorValue, 0, 724, 0, 500);
  int ms = 0;

  while(ms < threshold){
    sensorValue = analogRead(A7);
    threshold = map(sensorValue, 0, 1023, 0, 500);

    delay(1);
    ms++;

  }

  analogWrite(A3, 200);
  delay(50);


  // Print out the voltage value:
  Serial.print("sensorValue: ");
  Serial.println(sensorValue);
  Serial.print("threshold: ");
  Serial.println(threshold);

}