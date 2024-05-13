#include <Servo.h>

const int MAX_RECORDINGS = 500;
const int X_SERVO_PIN = 5;
const int Y_SERVO_PIN = 6;
const int JOYSTICK_BUTTON_PIN = A2;
const int LIGHT_PIN = 11;
const int RECORD_BUTTON_PIN = 9;
const int PLAYBACK_BUTTON = 8;
const int DELAY_MS = 10;
const int JOYSTICK_X_PIN = 0;
const int JOYSTICK_Y_PIN = 1;
const int MEMORY_WARNING_LED_PIN = 13;

Servo xServo;
Servo yServo;

int currentRecodingDuration = 0;
int currentIndex = 0;
byte xServoValues[MAX_RECORDINGS];
byte yServoValues[MAX_RECORDINGS];
byte lightValues[MAX_RECORDINGS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xServo.attach(X_SERVO_PIN);
  yServo.attach(Y_SERVO_PIN);
  pinMode(JOYSTICK_BUTTON_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(RECORD_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PLAYBACK_BUTTON, INPUT_PULLUP);
  pinMode(MEMORY_WARNING_LED_PIN, OUTPUT);
}

void recording(byte x, byte y, byte light) {
  if (currentIndex < MAX_RECORDINGS) {
    xServoValues[currentIndex] = x;
    yServoValues[currentIndex] = y;
    lightValues[currentIndex] = light;
    digitalWrite(MEMORY_WARNING_LED_PIN, LOW);
    if (currentIndex > 10){
      currentRecodingDuration = currentIndex;
    }
    currentIndex++;
  } else {
    digitalWrite(MEMORY_WARNING_LED_PIN, HIGH);
  }
}

void set_moving_head(byte x, byte y, byte light) {
  xServo.write(x);
  yServo.write(y);

  if (light == 0) {
    digitalWrite(LIGHT_PIN, HIGH);
  } else {
    digitalWrite(LIGHT_PIN, LOW);
  }
}

void playback() {
  if (currentIndex <= currentRecodingDuration) {
    set_moving_head(xServoValues[currentIndex], yServoValues[currentIndex], lightValues[currentIndex]);
    currentIndex++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  byte x = map(analogRead(JOYSTICK_X_PIN), 0, 1023, 0, 180);
  byte y = map(analogRead(JOYSTICK_Y_PIN), 0, 1023, 0, 180);
  byte light = digitalRead(JOYSTICK_BUTTON_PIN);

  if (!digitalRead(RECORD_BUTTON_PIN)) {
    recording(x, y, light);

  } else if (!digitalRead(PLAYBACK_BUTTON)) {
    playback();

  } else {
    //not recording
    currentIndex = 0;
  }

  if (digitalRead(PLAYBACK_BUTTON)) {
    set_moving_head(x, y, light);
  }

  delay(DELAY_MS);
}
