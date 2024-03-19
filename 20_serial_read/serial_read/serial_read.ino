void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char key = Serial.read();

    switch (key) {
      case '1':
        digitalWrite(9, HIGH);
        Serial.println("Green LED was turned ON");
        break;
      case '2':
        digitalWrite(9, LOW);
        Serial.println("Green LED was turned OFF");
        break;
      case '3':
        digitalWrite(10, HIGH);
        Serial.println("Yellow LED was turned ON");
        break;
      case '4':
        digitalWrite(10, LOW);
        Serial.println("Yellow LED was turned OFF");
        break;
      case '5':
        digitalWrite(11, HIGH);
        Serial.println("Red LED was turned ON");
        break;
      case '6':
        digitalWrite(11, LOW);
        Serial.println("Red LED was turned OFF");
        break;
    }
  }
}
