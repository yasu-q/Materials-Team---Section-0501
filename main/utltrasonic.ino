/* Ultrasonic sensor variables setup */
const int TRIG_PIN = A5;
const int ECHO_PIN = A4;

// SETUP
void ultrasonic_setup() {
  /* Ultrasonic sensor setup */
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

// ULTRASONIC SENSOR FUNCTIONS
/* 
  Utility
*/
long read_distance_information() {
  long duration = 0;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);        // Expected 10us delay from part
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  return duration;
}
/*
  Returns the distance the ultrasonic sensor is currently reading
  in cm
*/
int get_distance_cm() {
  long cm = read_distance_information();
  return usec_to_cm(cm);
}
/* 
  Functions that convert microsecond pulses on the ultrasonic sensor
  to their respective units
*/
long usec_to_cm(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}