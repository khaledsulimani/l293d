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

void setup() {
  // إعداد الأرجل كمخرجات
  pinMode(enA1, OUTPUT);
  pinMode(enB1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA2, OUTPUT);
  pinMode(enB2, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
  // تفعيل المحركات عبر PWM
  analogWrite(enA1, 255);  // سرعة كاملة
  analogWrite(enB1, 255);  // سرعة كاملة
  analogWrite(enA2, 255);  // سرعة كاملة
  analogWrite(enB2, 255);  // سرعة كاملة
}

void loop() {
  // التحرك للأمام لمدة 30 ثانية
  moveForward();
  delay(30000); // 30 ثانية

  // التوقف لمدة 1 دقيقة
  stopMotors();
  delay(60000); // 60 ثانية

  // التحرك للخلف لمدة 30 ثانية
  moveBackward();
  delay(30000); // 30 ثانية

  // التوقف لمدة 1 دقيقة
  stopMotors();
  delay(60000); // 60 ثانية

  // التوجه لليمين لمدة دقيقة
  turnRight();
  delay(60000); // 60 ثانية

  // التوجه لليسار لمدة دقيقة
  turnLeft();
  delay(60000); // 60 ثانية
}

// دالة التحرك للأمام
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}

// دالة التحرك للخلف
void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}

// دالة التوجه لليمين
void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}

// دالة التوجه لليسار
void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}

// دالة إيقاف المحركات
void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8,LOW);
}