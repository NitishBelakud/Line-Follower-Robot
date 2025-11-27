// Simple Line Follower Robot – Arduino UNO

// Sensor pins
const int LEFT_SENSOR  = 2;
const int RIGHT_SENSOR = 3;

// Motor driver pins (L293D)
const int ENA = 5;   // PWM left motor
const int IN1 = 6;
const int IN2 = 7;

const int ENB = 9;   // PWM right motor
const int IN3 = 10;
const int IN4 = 11;

// Motor speed (0–255)
int baseSpeed = 160;

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Enable motors
  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void loop() {
  int left  = digitalRead(LEFT_SENSOR);   // HIGH = white, LOW = black
  int right = digitalRead(RIGHT_SENSOR);

  if (left == HIGH && right == HIGH) {
    // Both on white -> go straight (no line under sensors, but assume centered)
    forward();
  }
  else if (left == LOW && right == HIGH) {
    // Left on black -> robot is left of the line -> turn LEFT
    turnLeft();
  }
  else if (left == HIGH && right == LOW) {
    // Right on black -> robot is right of the line -> turn RIGHT
    turnRight();
  }
  else { // left == LOW && right == LOW
    // Both on black -> on the line or intersection -> go straight (or slow)
    forward();
  }
}

// ---- Motor control helpers ----
void forward() {
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  // Left motor slow / backward, right motor forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // left backward

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);   // right forward

  analogWrite(ENA, baseSpeed / 2);
  analogWrite(ENB, baseSpeed);
}

void turnRight() {
  // Left motor forward, right motor slow / backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);   // left forward

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // right backward

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed / 2);
}
