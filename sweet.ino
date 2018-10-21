/**************************************************************
sweet.ino
BlackBug Engineering
07.11.2018
https://github.com/dbprof/sweet
***************************************************************/

///////////////////////////////ДАТЧИК_ПРИСУТСТВИЯ///////////////////////////////
#define SENSOR_PIN 10

///////////////////////////////СЕРВОПРИВОД///////////////////////////////
// добавляем библиотеку для работы с сервоприводами
#include <Servo.h> 
#define SSERVO_PIN 9
Servo SServo;
bool isServoAttached = false;
void attachServo() {
  if (!isServoAttached) {
    SServo.attach(SSERVO_PIN);
    isServoAttached = true;
  }
}
void detachServo() {
  if (isServoAttached) {
    SServo.detach();
    isServoAttached = false;
  }
}
void closeGate() {
  attachServo();
  SServo.write(100);
  delay(300);
  SServo.write(98);
  delay(300);
  SServo.write(102);
  delay(300);
  SServo.write(100);
  delay(300);
  detachServo();
}
void openGate() {
  attachServo();
  SServo.write(108);
  delay(300);
  SServo.write(106);
  delay(300);
  SServo.write(110);
  delay(300);
  SServo.write(108);
  delay(300);
  detachServo();
}
void passOne() {
  openGate();
  delay(2000);
  closeGate();
}

void setup() {
  closeGate();

}

void loop() {
  if (digitalRead(SENSOR_PIN)) 
  {
    delay(1000);
    passOne();
    delay(1000);
    return;
  }

}
