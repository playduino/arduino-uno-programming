#include <Servo.h>

Servo xServo;
Servo yServo;

byte currentIndex = 0;
volatile byte xServoValues[200];
volatile byte yServoValues[200];
volatile byte lightValues[200];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xServo.attach(5);
  yServo.attach(6);
  pinMode(A2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte x = map(analogRead(0), 0, 1023, 0, 180);
  byte y = map(analogRead(1), 0, 1023, 0, 180);
  byte light = digitalRead(A2);

  if (!digitalRead(9)) {
    //recording
    if (currentIndex < 200) {
      xServoValues[currentIndex] = x;
      yServoValues[currentIndex] = y;
      lightValues[currentIndex] = light;

      currentIndex++;
    } else {
      Serial.println("full memory");
    }

  } else if (!digitalRead(8)) {
    Serial.println("play");
    //playback
    xServo.write(xServoValues[currentIndex]);
    yServo.write(yServoValues[currentIndex]);

    if (lightValues[currentIndex] == 0) {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }

    if (currentIndex < 200) {
      currentIndex++;
    }

  } else {
    //not recording
    currentIndex = 0;
  }

  if (digitalRead(8)) {
    if (light == 0) {
      digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
    }

    xServo.write(x);
    yServo.write(y);
  }

  delay(10);
}
