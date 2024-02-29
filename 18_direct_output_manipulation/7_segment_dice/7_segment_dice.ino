void setup() {
  // put your setup code here, to run once:
  DDRD = B11110000;
  DDRB = B00001111;
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int randomNumber = 1; randomNumber < 7; randomNumber++) {
    switch (randomNumber) {
      case 1:
        PORTB = B00000111;
        PORTD = B10010000;
        break;
      case 2:
        PORTB = B00000010;
        PORTD = B01000000;
        break;
      case 3:
        PORTB = B00000011;
        PORTD = B00000000;
        break;
      case 4:
        PORTB = B00000001;
        PORTD = B10010000;
        break;
      case 5:
        PORTB = B00000001;
        PORTD = B00100000;
        break;
      case 6: PORTB = B00000000; PORTD = B00100000;
    }
    delay(1000);
  }
}
