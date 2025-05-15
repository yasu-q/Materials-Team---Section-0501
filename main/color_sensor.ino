/* Color sensor variables setup */ 
const int COLOR_S0 = 8;
// S1 not needed
const int COLOR_S2 = 9;
const int COLOR_S3 = 10;
const int COLOR_OUT = 11;

// Variables for Color Pulse Width Measurements
 
int red_pw = 0;
int green_pw = 0;
int blue_pw = 0;

// SETUP
void color_sensor_setup() {
  /* Color sensor setup */
  // Set COLOR_S0 - COLOR_S3 as outputs
  pinMode(COLOR_S0, OUTPUT);
  pinMode(COLOR_S2, OUTPUT);
  pinMode(COLOR_S3, OUTPUT);
  
  // Set Sensor output as input
  pinMode(COLOR_OUT, INPUT);
  
  // Set Pulse Width scaling to 20%
  digitalWrite(COLOR_S0,HIGH);
}

// COLOR SENSOR FUNCTIONS
int get_red_pw() {
  // Set sensor to read red only
  digitalWrite(COLOR_S2,LOW);
  digitalWrite(COLOR_S3,LOW);
  // Return the value
  return pulseIn(COLOR_OUT, LOW);
}

int get_green_pw() {
  // Set sensor to read green only
  digitalWrite(COLOR_S2,HIGH);
  digitalWrite(COLOR_S3,HIGH);
  // Return the value
  return pulseIn(COLOR_OUT, LOW);
}

int get_blue_pw() {
  // Set sensor to read blue only
  digitalWrite(COLOR_S2,LOW);
  digitalWrite(COLOR_S3,HIGH);
  // Return the value
  return pulseIn(COLOR_OUT, LOW);
}