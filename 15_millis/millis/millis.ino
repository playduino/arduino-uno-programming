void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

unsigned long storedTimeStampRed = 0;
unsigned long storedTimeStampGreen = 0;

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();

  if(currentMillis - storedTimeStampRed  >= 300){
    storedTimeStampRed = currentMillis;
    digitalWrite(2, !digitalRead(2));
  }

  if(currentMillis - storedTimeStampGreen  >= 400){
    storedTimeStampGreen = currentMillis;
    digitalWrite(3, !digitalRead(3));
  }

}
