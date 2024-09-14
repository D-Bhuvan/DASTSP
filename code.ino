// Pin configuration
const int ldrPinX1 = A0; // LDR pin for horizontal (X-axis) - Motor 1
const int ldrPinX2 = A1; // LDR pin for horizontal (X-axis) - Motor 2
const int ldrPinY1 = A2; // LDR pin for vertical (Y-axis) - Motor 3
const int ldrPinY2 = A3; // LDR pin for vertical (Y-axis) - Motor 4

const int motorPinX1 = 9; // Motor pin for horizontal (X-axis) - Motor 1
const int motorPinX2 = 10; // Motor pin for horizontal (X-axis) - Motor 2
const int motorPinY1 = 11; // Motor pin for vertical (Y-axis) - Motor 3
const int motorPinY2 = 12; // Motor pin for vertical (Y-axis) - Motor 4

// Motor control parameters
const int motorSpeed = 100; // Adjust the motor speed as needed
const int motorDirectionPinX1 = 2; // Motor direction pin for horizontal (X-axis) - Motor 1
const int motorDirectionPinX2 = 3; // Motor direction pin for horizontal (X-axis) - Motor 2
const int motorDirectionPinY1 = 4; // Motor direction pin for vertical (Y-axis) - Motor 3
const int motorDirectionPinY2 = 5; // Motor direction pin for vertical (Y-axis) - Motor 4

void setup() {
  Serial.begin(9600);
  pinMode(motorDirectionPinX1, OUTPUT);
  pinMode(motorDirectionPinX2, OUTPUT);
  pinMode(motorDirectionPinY1, OUTPUT);
  pinMode(motorDirectionPinY2, OUTPUT);
}

void loop() {
  int ldrValueX1 = analogRead(ldrPinX1);
  int ldrValueX2 = analogRead(ldrPinX2);
  int ldrValueY1 = analogRead(ldrPinY1);
  int ldrValueY2 = analogRead(ldrPinY2);

  // Map LDR values to motor speed (adjust the values based on your LDR characteristics)
  int motorSpeedX1 = map(ldrValueX1, 0, 1023, -motorSpeed, motorSpeed);
  int motorSpeedX2 = map(ldrValueX2, 0, 1023, -motorSpeed, motorSpeed);
  int motorSpeedY1 = map(ldrValueY1, 0, 1023, -motorSpeed, motorSpeed);
  int motorSpeedY2 = map(ldrValueY2, 0, 1023, -motorSpeed, motorSpeed);

  // Print LDR values and corresponding motor speeds
  Serial.print("LDR X1: ");
  Serial.print(ldrValueX1);
  Serial.print("  Motor Speed X1: ");
  Serial.print(motorSpeedX1);
  Serial.print("  |  LDR X2: ");
  Serial.print(ldrValueX2);
  Serial.print("  Motor Speed X2: ");
  Serial.print(motorSpeedX2);
  Serial.print("  |  LDR Y1: ");
  Serial.print(ldrValueY1);
  Serial.print("  Motor Speed Y1: ");
  Serial.print(motorSpeedY1);
  Serial.print("  |  LDR Y2: ");
  Serial.print(ldrValueY2);
  Serial.print("  Motor Speed Y2: ");
  Serial.println(motorSpeedY2);

  // Adjust motor direction based on motor speed
  digitalWrite(motorDirectionPinX1, (motorSpeedX1 >= -90) ? HIGH : LOW);
  digitalWrite(motorDirectionPinX2, (motorSpeedX2 >= -90) ? HIGH : LOW);
  digitalWrite(motorDirectionPinY1, (motorSpeedY1 >= -90) ? HIGH : LOW);
  digitalWrite(motorDirectionPinY2, (motorSpeedY2 >= -90) ? HIGH : LOW);

  // Set motor speeds
  analogWrite(motorPinX1, abs(motorSpeedX1));
  analogWrite(motorPinX2, abs(motorSpeedX2));
  analogWrite(motorPinY1, abs(motorSpeedY1));
  analogWrite(motorPinY2, abs(motorSpeedY2));

  delay(1000); // Adjust the delay based on your application requirements
}
