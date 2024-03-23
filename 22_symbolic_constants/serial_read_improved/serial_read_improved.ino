#define GREEN 9
#define YELLOW 10
#define RED 11

void manipulateLED(int color, bool state) {
  digitalWrite(color, state);
  switch (color) {
    case GREEN: Serial.print("Green"); break;
    case YELLOW: Serial.print("Yellow"); break;
    case RED: Serial.print("Red"); break;
  }
  Serial.print(" LED was turned ");
  if (state) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char key = Serial.read();

    switch (key) {
      case '1':
        manipulateLED(GREEN, HIGH);
        break;
      case '2':
        manipulateLED(GREEN, LOW);
        break;
      case '3':
        manipulateLED(YELLOW, HIGH);
        break;
      case '4':
        manipulateLED(YELLOW, LOW);
        break;
      case '5':
        manipulateLED(RED, HIGH);
        break;
      case '6':
        manipulateLED(RED, LOW);
        break;
    }
  }
}
