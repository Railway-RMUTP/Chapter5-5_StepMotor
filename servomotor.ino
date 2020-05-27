#include <ESP32Servo.h>

Servo myservo; //ประกาศตัวแปรแทน Servo
char value = '0'; //ตัวแปรไว้เก็บค่าจาก serial.read

void setup()
{
  myservo.attach(13); // กำหนดขา 13 ควบคุม Servo
}
void loop()
{
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(2000);
  myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
  delay(2000);
//  myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 90

}


  

//https://www.arduinolibraries.info/libraries/esp32-servo  = libraries
