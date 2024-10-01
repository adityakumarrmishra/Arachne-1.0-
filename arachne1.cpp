#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

#define SERVO_MIN 150  // Adjust this value based on your servo
#define SERVO_MAX 600  // Adjust this value based on your servo

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int c = 0;

unsigned long previousMillis = 0;
unsigned long interval = 100;
int leg1Step = 0;
int leg2Step = 0;
bool leg1Done = false;
bool leg2Done = false;

// Define servo angles and delays for leg1 and leg2
const int leg1Angles[][2] = {
  {2, 90}, {2, 20}, {6, 120}, {7, 0}, {8, 70}, {6, 60},
  {1, 180}, {0, 50}, {2, 80}, {0, 100}, {1, 90}, {8, 0},
  {7, 80}, {6, 120}
};

const int leg2Angles[][2] = {
  {3, 120}, {3, 180}, {9, 40}, {10, 180}, {11, 30}, {9, 100},
  {4, 0}, {5, 150}, {3, 120}, {5, 70}, {4, 70}, {11, 80},
  {10, 100}, {9, 40}
};

const int leg1Steps = sizeof(leg1Angles) / sizeof(leg1Angles[0]);
const int leg2Steps = sizeof(leg2Angles) / sizeof(leg2Angles[0]);

void setup() {
  Serial.begin(9600);
  Serial.println("PCA9685 Servo Test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  setServoAngle(0, 90);
  setServoAngle(1, 100);
  setServoAngle(2, 80);
  setServoAngle(3, 120);
  setServoAngle(4, 70);
  setServoAngle(5, 100);
  setServoAngle(6, 120);
  setServoAngle(7, 80);
  setServoAngle(8, 0);
  setServoAngle(9, 40);
  setServoAngle(10, 100);
  setServoAngle(11, 80);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (!leg1Done) {
      leg1();
    } else if (!leg2Done) {
      leg2();
    } else {
      // Both legs are done, reset steps for the next forward cycle
      leg1Done = false;
      leg2Done = false;
      leg1Step = 0;
      leg2Step = 0;
    }
  }

  if (c == 0) {
    stance();
    delay(1000);
    hello();
    stance();
    delay(5000);
    c++;
  }
}

void leg1() {
  if (leg1Step < leg1Steps) {
    setServoAngle(leg1Angles[leg1Step][0], leg1Angles[leg1Step][1]);
    leg1Step++;
    if (leg1Step >= leg1Steps) {
      leg1Done = true;
    }
  }
}

void leg2() {
  if (leg2Step < leg2Steps) {
    setServoAngle(leg2Angles[leg2Step][0], leg2Angles[leg2Step][1]);
    leg2Step++;
    if (leg2Step >= leg2Steps) {
      leg2Done = true;
    }
  }
}

void forward() {
  leg1();
  leg2();
}

void stance() {
  // leg1
  setServoAngle(0, 110);
  setServoAngle(1, 100);
  setServoAngle(2, 90);
  // leg2
  setServoAngle(3, 120);
  setServoAngle(4, 70);
  setServoAngle(5, 70);
  // leg3
  setServoAngle(6, 120);
  setServoAngle(7, 80);
  setServoAngle(8, 0);
  // leg4
  setServoAngle(9, 40);
  setServoAngle(10, 110);
  setServoAngle(11, 90);
}

void hello() {
  setServoAngle(1, 180);
  delay(250);
  for (int i = 0; i < 3; i++) {
    setServoAngle(0, 50);
    delay(250);
    setServoAngle(0, 110);
    delay(100);
  }
  setServoAngle(1, 180);
  setServoAngle(0, 110);
  setServoAngle(1, 100);
  setServoAngle(2, 90);
}

void stand() {
  setServoAngle(0, 0);
  setServoAngle(1, 10);
  setServoAngle(4, 120);
  setServoAngle(5, 100);
  setServoAngle(8, 80);
  setServoAngle(8, 80);
}

void setServoAngle(uint8_t servoNumber, uint16_t angle) {
  // Convert angle to PWM value
  uint16_t pwmValue = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(servoNumber, 0, pwmValue);  // The third argument is always 0 for Adafruit_PWMServoDriver
}