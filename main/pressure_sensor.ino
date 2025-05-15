const int sensor_pin = A0;

void pressure_sensor_setup() {
  pinMode(sensor_pin, INPUT);
}

int get_weight_analog() {
  return analogRead(sensor_pin);
}