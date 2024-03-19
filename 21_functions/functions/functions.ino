void blinkLed(int pin) {
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blinkLed(9);
  blinkLed(10);
  blinkLed(11);
  delay(2000);

}
