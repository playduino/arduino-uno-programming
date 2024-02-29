void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
}

bool buttonWasNotPressed = true;

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(7)) {
    buttonWasNotPressed = true;
    delay(20);
  }

  if (!digitalRead(7) && buttonWasNotPressed) {
    buttonWasNotPressed = false;
    randomSeed(millis());
    int myRandomNumber = random(1, 7);
    Serial.print(myRandomNumber, DEC);
    delay(20);
  }
}
