int motorPin1 = 16;// Blue - 28BYJ48 pin 1
int motorPin2 = 17;// Green - 28BYJ48 pin 2
int motorPin3 = 18;// Yellow - 28BYJ48 pin 3
int motorPin4 = 19;// Orange - 28BYJ48 pin 4
int motorSpeed = 4; //variable to set stepper speed
char value = '0'; //ตัวแปรไว้เก็บค่าจาก serial.read
void setup() {
  //คำสั่งที่มีไว้สำหรับกำหนดการทำงานของ pin ให้ทำงานเป็นแบบ INPUT หรือ OUTPUT
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) //เป็นการตรวจสอบว่ามีการพิมพ์ข้อความเข้ามาหรือไม่
{
    value = Serial.read();   //เป็นการรับค่าจาก serial Monitor
    Serial.println(value);
}
  
  if (value == '1') {
    counterclockwise(); //หมุนวนซ้าย หมุนทวนเข็มนาฬิกา
  }
  if (value == '2') {
    clockwise(); //หมุนวนขวา หมุนตามเข็มนาฬิกา
  }
  if (value == '0') { //หยุดหมุน
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
}

void counterclockwise () {
  // 1
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);
  // 2
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay (motorSpeed);
  // 3
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);
  // 4
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motorSpeed);
}




void clockwise() {
  // 1
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motorSpeed);
  // 2
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay (motorSpeed);
  // 3
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);
  // 4
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motorSpeed);
}
