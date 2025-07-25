# RC Car with Ultrasonic Sensor and L293D Motor Driver 🚗

This project demonstrates the control of an RC car using an *Arduino* and the *L293D Motor Driver. The car is capable of executing basic movements such as moving forward, backward, turning left, and turning right. Additionally, an **ultrasonic sensor* is integrated to detect obstacles and modify the car's movement accordingly.

---

## Tasks Overview 🎯

### Task 1: Obstacle Detection with Ultrasonic Sensor 🚧

In this task, we use an *ultrasonic sensor* to detect obstacles in front of the car. If the car detects an object within 10 cm, it will stop, move backward for a few seconds, and then turn right to avoid the obstacle.

### Task 2: Predefined Motor Movements ⏱

In this task, the car will execute a series of predefined movements:
1. Move forward for 30 seconds.
2. Stop for 1 minute.
3. Move backward for 30 seconds.
4. Stop again for 1 minute.
5. Turn right for 1 minute.
6. Turn left for 1 minute.

---

## Hardware Required 🛠

- *4 DC Motors* ⚙
- *L293D Motor Driver* 🏎
- *Ultrasonic Sensor* 📡
- *Arduino/Controller* (any compatible microcontroller) 🖥

---

## Wiring Diagram 📊

1. *Motor Connections*: Connect the 4 DC motors to the L293D motor driver.
2. *Ultrasonic Sensor*: Connect the ultrasonic sensor to the microcontroller (Arduino).
3. Ensure that the L293D pins are correctly wired for motor control.

---

## Wiring Instructions for task 1 ⚡

| Component                      | Pin Number | Description                                                                                     |
|---------------------------------|------------|-------------------------------------------------------------------------------------------------|
| *L293D Motor Driver (Motor 1)* | Pin 11     | *enA1*: Motor driver enable for left motor (Motor 1)                                          |
| *L293D Motor Driver (Motor 2)* | Pin 2      | *enB1*: Motor driver enable for left motor (Motor 1)                                          |
| *L293D Motor Driver (Motor 1)* | Pin 3      | *in1*: Control pin for left motor (Motor 1)                                                   |
| *L293D Motor Driver (Motor 1)* | Pin 4      | *in2*: Control pin for left motor (Motor 1)                                                   |
| *L293D Motor Driver (Motor 2)* | Pin 5      | *in3*: Control pin for second motor (Motor 2)                                                 |
| *L293D Motor Driver (Motor 2)* | Pin 6      | *in4*: Control pin for second motor (Motor 2)                                                 |
| *L293D Motor Driver (Motor 3)* | Pin 12     | *enA2*: Motor driver enable for third motor (Motor 3)                                         |
| *L293D Motor Driver (Motor 4)* | Pin 13     | *enB2*: Motor driver enable for fourth motor (Motor 4)                                        |
| *L293D Motor Driver (Motor 3)* | Pin 8      | *in5*: Control pin for third motor (Motor 3)                                                  |
| *L293D Motor Driver (Motor 3)* | Pin 7      | *in6*: Control pin for third motor (Motor 3)                                                  |
| *L293D Motor Driver (Motor 4)* | Pin 9      | *in7*: Control pin for fourth motor (Motor 4)                                                 |
| *L293D Motor Driver (Motor 4)* | Pin 10     | *in8*: Control pin for fourth motor (Motor 4)                                                 |
| *Ultrasonic Sensor (Trigger)*  | Pin A0     | *trigPin*: Sends pulse to ultrasonic sensor to measure distance                               |
| *Ultrasonic Sensor (Echo)*     | Pin A1     | *echoPin*: Receives echo signal from ultrasonic sensor to calculate distance                  |

## Task 1: Obstacle Detection with Ultrasonic Sensor 🚧

The car uses an *ultrasonic sensor* to measure the distance to any objects in front of it. If the distance is less than *10 cm*, the car will:
- Stop the motors.
- Move backward for 2 seconds.
- Turn right for 2 seconds.

### Code for Task 1 (Obstacle Detection) 📝

```cpp
// L293D Motor Driver pins
int enA1 = 11;
int enB1 = 2;
int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

// Ultrasonic Sensor Pins
const int trigPin = A0;
const int echoPin = A1;

void setup() {
  Serial.begin(9600);

  // Motor pins setup
  pinMode(enA1, OUTPUT); pinMode(enB1, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);

  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // PWM setup for motor speed control
  analogWrite(enA1, 255);  // Full speed
  analogWrite(enB1, 255);  // Full speed
}

void loop() {
  long distance = readDistanceCM();
  Serial.println(distance);

  // Reaction based on the distance
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

  delay(100); // Simple delay for continuous monitoring
}

// Function to read distance from the ultrasonic sensor
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

// Motor movement functions
void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}
```
---

## Wiring Instructions for task 2 ⚡

| Component                      | Pin Number | Description                                                                                     |
|---------------------------------|------------|-------------------------------------------------------------------------------------------------|
| *L293D Motor Driver (Motor 1)* | Pin 11     | *enA1*: Motor driver enable for left motor (Motor 1)                                          |
| *L293D Motor Driver (Motor 2)* | Pin 2      | *enB1*: Motor driver enable for left motor (Motor 1)                                          |
| *L293D Motor Driver (Motor 1)* | Pin 3      | *in1*: Control pin for left motor (Motor 1)                                                   |
| *L293D Motor Driver (Motor 1)* | Pin 4      | *in2*: Control pin for left motor (Motor 1)                                                   |
| *L293D Motor Driver (Motor 2)* | Pin 5      | *in3*: Control pin for second motor (Motor 2)                                                 |
| *L293D Motor Driver (Motor 2)* | Pin 6      | *in4*: Control pin for second motor (Motor 2)                                                 |
| *L293D Motor Driver (Motor 3)* | Pin 12     | *enA2*: Motor driver enable for third motor (Motor 3)                                         |
| *L293D Motor Driver (Motor 4)* | Pin 13     | *enB2*: Motor driver enable for fourth motor (Motor 4)                                        |
| *L293D Motor Driver (Motor 3)* | Pin 8      | *in5*: Control pin for third motor (Motor 3)                                                  |
| *L293D Motor Driver (Motor 3)* | Pin 7      | *in6*: Control pin for third motor (Motor 3)                                                  |
| *L293D Motor Driver (Motor 4)* | Pin 9      | *in7*: Control pin for fourth motor (Motor 4)                                                 |
| *L293D Motor Driver (Motor 4)* | Pin 10     | *in8*: Control pin for fourth motor (Motor 4)                                                 |

---

## Task 2: Predefined Motor Movements ⏱

In this task, the RC car is programmed to execute a series of predefined motor movements based on time intervals. The movements include:
1. Moving forward for *30 seconds*.
2. Stopping for *1 minute*.
3. Moving backward for *30 seconds*.
4. Stopping again for *1 minute*.
5. Turning right for *1 minute*.
6. Turning left for *1 minute*.





### Code for Task 2 (Predefined Motor Movements) 📝

```cpp
// L293D Motor Driver pins
int enA1 = 11;
int enB1 = 2;
int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

// Motor 2 (Right motors)
int enA2 = 12;
int enB2 = 13;
int in5 = 8;
int in6 = 7;
int in7 = 9;
int in8 = 10;

void setup() {
  // Motor pins setup
  pinMode(enA1, OUTPUT); pinMode(enB1, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  pinMode(enA2, OUTPUT); pinMode(enB2, OUTPUT);
  pinMode(in5, OUTPUT); pinMode(in6, OUTPUT); pinMode(in7, OUTPUT); pinMode(in8, OUTPUT);

  // PWM setup for motor speed control
  analogWrite(enA1, 255);  // Full speed
  analogWrite(enB1, 255);  // Full speed
  analogWrite(enA2, 255);  // Full speed
  analogWrite(enB2, 255);  // Full speed
}

void loop() {
  // Task 2: Move forward for 30 seconds
  moveForward();
  delay(30000); // 30 seconds

  // Stop for 1 minute
  stopMotors();
  delay(60000); // 60 seconds

  // Move backward for 30 seconds
  moveBackward();
  delay(30000); // 30 seconds

  // Stop for 1 minute
  stopMotors();
  delay(60000); // 60 seconds

  // Turn right for 1 minute
  turnRight();
  delay(60000); // 60 seconds

  // Turn left for 1 minute
  turnLeft();
  delay(60000); // 60 seconds
}

// Motor movement functions
void moveForward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}
```
---

## 📸 Project Results
### *task 1 video*:

https://github.com/user-attachments/assets/580e28ab-d7da-4c7d-b050-e0c0a2829972



### *task 2 circuit diagram + one dc with + rbm*: ![صورة واتساب بتاريخ 1447-01-30 في 06 56 38_4ac2368b](https://github.com/user-attachments/assets/ae5c5472-e68c-4707-a754-a820c408b407)


### *task 2 change to other dc with + rbm*: ![صورة واتساب بتاريخ 1447-01-30 في 06 56 51_e135b6b1](https://github.com/user-attachments/assets/b54aa00b-0f63-4251-b6f1-31ed1fb70f56)

 ### *task 1 circuit diagram*:  *<img width="2369" height="1052" alt="image" src="https://github.com/user-attachments/assets/d30ab041-9239-4198-9b86-63ad825fda72" />

---

## 🧑‍💻 Author
- **khaled mahmoud sulaimani** – [@khaledsulimani](https://github.com/khaledsulimani)

---
