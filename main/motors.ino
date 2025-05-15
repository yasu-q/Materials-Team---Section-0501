// Pins for the first motor driver
const int MOT_1_C1 = 4;
const int MOT_1_C2 = 7;
const int MOT_1_PWM = 5;
// Pins for the second motor driver
const int MOT_2_C1 = 12;
const int MOT_2_C2 = 13;
const int MOT_2_PWM = 6;

// Time for a 90 degree rotation at max speed
const int quarter_turn = 1417;

// SETUP
void motors_setup() {
  // Set all pins to output
  pinMode(MOT_1_C1, OUTPUT);
  pinMode(MOT_1_C2, OUTPUT);
  pinMode(MOT_1_PWM, OUTPUT);
  pinMode(MOT_2_C1, OUTPUT);
  pinMode(MOT_2_C2, OUTPUT);
  pinMode(MOT_2_PWM, OUTPUT);
}

// MOVEMENT FUNCTIONS
/*
  Moves forward for a specific amount of time with
  a given speed
*/
void forward(int time, int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, HIGH);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, HIGH);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, speed);

  delay(time);

  // Stop moving

  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, 0);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, 0);
}
/*
  Moves backward for a specific amount of time with
  a given speed
*/
void backward(int time, int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, HIGH);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, HIGH);
  analogWrite(MOT_2_PWM, speed);

  delay(time);

  // Stop moving

  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, 0);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, 0);
}
/*
  Turns for a specific amount of time with 
  a given speed
*/
void turn_right(int time, int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, HIGH);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, HIGH);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, speed);

  delay(time);

  // Stop moving

  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, 0);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, 0);
}
void turn_left(int time, int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, HIGH);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, HIGH);
  analogWrite(MOT_2_PWM, speed);

  delay(time);

  // Stop moving

  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, 0);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, 0);
}


// granular
void turn_right_ns(int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, HIGH);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, HIGH);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, speed);
}
void turn_left_ns(int speed) {
  // Motor one
  digitalWrite(MOT_1_C1, HIGH);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, speed);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, HIGH);
  analogWrite(MOT_2_PWM, speed);
}
void motor_stop() {
  // Motor one
  digitalWrite(MOT_1_C1, LOW);
  digitalWrite(MOT_1_C2, LOW);
  analogWrite(MOT_1_PWM, 0);
  // Motor two
  digitalWrite(MOT_2_C1, LOW);
  digitalWrite(MOT_2_C2, LOW);
  analogWrite(MOT_2_PWM, 0);
}
