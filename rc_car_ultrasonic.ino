// تعريف أرجل L293D للمحركات الأربعة
// القطعة الأولى L293D
int enA1 = 11;
int enB1 = 2;
int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

// القطعة الثانية L293D
int enA2 = 12;
int enB2 = 13;
int in5 = 8;
int in6 = 7;
int in7 = 9;
int in8 = 10;

// أرجل حساس الموجات فوق الصوتية
const int trigPin = A0;
const int echoPin = A1;

void setup() {
  Serial.begin(9600);

  // إعداد الأرجل كمخرجات
  pinMode(enA1, OUTPUT); pinMode(enB1, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  pinMode(enA2, OUTPUT); pinMode(enB2, OUTPUT);
  pinMode(in5, OUTPUT); pinMode(in6, OUTPUT); pinMode(in7, OUTPUT); pinMode(in8, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(enA1, 255);
  analogWrite(enB1, 255);
  analogWrite(enA2, 255);
  analogWrite(enB2, 255);
}

void loop() {
  long distance = readDistanceCM();
  Serial.println(distance);

  // رد الفعل بناءً على المسافة
  if (distance < 10) {
    stopMotors();
    delay(1000);
    moveBackward();
    delay(2000);
    turnRight();
    delay(2000);
  } else {
    moveForward();
  }

  delay(100); // مهلة بسيطة للمراقبة المستمرة
}

// دالة قراءة المسافة من الحساس
long readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

// دوال الحركة
void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH); digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH); digitalWrite(in8, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW); digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW); digitalWrite(in8, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);  digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH); digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);  digitalWrite(in8, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH); digitalWrite(in8, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
  digitalWrite(in5, LOW); digitalWrite(in6, LOW);
  digitalWrite(in7, LOW); digitalWrite(in8,LOW);
}
