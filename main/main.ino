#define PI 3.1415
#define FOAM 0
#define PLA 1

#define LIGHT 0
#define MEDIUM 1
#define HEAVY 2

void setup() {
  wifi_setup();
  ultrasonic_setup();
  color_sensor_setup();
  motors_setup();
  pressure_sensor_setup();

  // ULTRASONIC SETUP
  Serial.begin(9600);
}

void loop() {
  // Execute mission
  delay(500);
  phase_one();
  delay(2000);
  forward(1250, 200);
  while (get_Xpos() < 3.85) {
    detect_obstacle();
  }
  wifi_println("mission complete");
  delay(20000);

  // int type = read_material_type();
  // Serial.println(type);
  // delay(200);
  // if (type == PLA) {
  //   Serial.println("it's PLA");
  // } else if (type == FOAM) {
  //   Serial.println("it's foam");
  // }

  // delay(500);

  // turn_toP(PI/2);
  // delay(1000);
  // turn_toP(-(PI/2));
  // delay(1000);

  // turn_to_granular(PI/2);
  // delay(1000);
  // turn_to_granular(-(PI/2));
  // delay(1000);

  // Serial.println(get_distance_cm());
  // delay(100);
}

/*
  Navigation function 
*/
void phase_one() {
  // turn_to(PI/2);       // Move and face objective
  // delay(300);          
  // forward(1800, 255);  // Move to midway point
  // delay(1500);
  // turn_to(-(PI/2));    // Face scoop to objective
  // delay(1500);
  // backward(2800, 255); // Drive into the objective
  // delay(1500);         // Give it a second

  double y_pos = get_Ypos();
  // Face 45 deg out
  if (y_pos > 1) {
    turn_to(-(PI/4));
  } else {
    turn_to(PI/4);
  }
  delay(500);
  forward(2000, 255);   // Move 45 deg out
  delay(500);
  move_to_Xb(0.285);    // Move in front of objective
  // Face objective
  if (y_pos > 1) {
    turn_toP(PI/2);
  } else {
    turn_toP(-(PI/2));
  }
  // Back up into objective
  backward(4000, 255);

  wifi_println("Material characteristics:");
  delay(100);
  // Read color sensor data
  int type = read_material_type();
  if (type == PLA) {
    wifi_println("it's PLA");
  } else if (type == FOAM) {
    wifi_println("it's foam");
  }
  // Read weight sensor
  int val = read_weight_type();
  if (val == LIGHT) {
    wifi_println("light");
  } else if (val == HEAVY) {
    wifi_println("heavy");
  } else {
    wifi_println("medium");
  }
  delay(100);
  wifi_println("-------------------------");
}
/*
  Turns to the input parameter. Heading must be between [-PI, PI]
*/
void turn_to(double heading) {
  int speed = 200;
  double threshhold = 0.06;
  int del = 10;
  int motor_len = 10;
  double cur_heading = get_heading();

  while(abs(heading - cur_heading) > threshhold) {
    cur_heading = get_heading();
    if (heading - cur_heading < 0) {
      turn_right(motor_len, speed);
    } else {
      turn_left(motor_len, speed);
    }
    delay(del);
  }
}
// Different version
void turn_toP(double heading) {
  int speed = 190;
  double threshhold = 0.05;
  int del = 5;
  int motor_len = 8;
  double cur_heading = get_heading();

  while(abs(heading - cur_heading) > threshhold) {
    if (heading - cur_heading < 0) {
      turn_right(motor_len, speed);
    } else {
      turn_left(motor_len, speed);
    }
    delay(del);
    cur_heading = get_heading();
  }
}
// granular
void turn_to_granular(double heading) {
  int speed = 170;
  double threshhold = 0.03;
  int del = 5;
  double cur_heading = get_heading();

  while(abs(heading - cur_heading) > threshhold) {
    if (cur_heading != -1) {
      if (heading - cur_heading < 0) {
        turn_right_ns(speed);
      } else {
        turn_left_ns(speed);
      }
    } else {
      motor_stop();
    }
    delay(del);
    cur_heading = get_heading(); 
  }
  motor_stop();
}
/*
  Returns 0 for foam and 1 for PLA
*/
int read_material_type() {
  // just checks green cause idfk i'm lazy it'll deadass prob work
  int value_count = 10;
  double green_threshold = 45;

  double green_vals[value_count];

  for (int i = 0; i < value_count; i++) {
    green_vals[i] = get_green_pw();
    delay(50);
  }
  double average_green = average(green_vals, value_count);
  
  Serial.println(average_green);

  return average_green > green_threshold ? FOAM : PLA;
}

int read_weight_type() {
  // just checks green cause idfk i'm lazy it'll deadass prob work
  int value_count = 10;
  double weight_thr = 850;

  double vals[value_count];

  for (int i = 0; i < value_count; i++) {
    vals[i] = get_weight_analog();
    delay(50);
  }
  double avrg = average(vals, value_count);
  
  Serial.println(avrg);

  return avrg < weight_thr ? HEAVY : LIGHT;
}

// void turn_to(double heading) {
//   double range = 0.5;

//   double cur_heading = get_heading();

//   while (abs(heading - cur_heading) > range) {
//     cur_heading = get_heading();

//     turn_right(20, 255);

//     delay(50);
//   }
// }

void move_to_X(double to_x) {
  double tolerance = 0.07;
  int speed = 200;
  int len = 20;
  int del = 50;

  double x_pos = get_Xpos();
  
  if (x_pos - to_x > 0) {
    turn_to(PI);
  } else {
    turn_to(0);
  }

  while (abs(get_Xpos() - to_x) > tolerance) {
    forward(len, speed);
    delay(del);
  }
}

void move_to_Xb(double to_x) {
  double tolerance = 0.07;
  int speed = 180;
  int len = 20;
  int del = 50;

  double x_pos = get_Xpos();
  
  if (x_pos - to_x > 0) {
    turn_to(0);
  } else {
    turn_to(PI);
  }

  while (abs(get_Xpos() - to_x) > tolerance) {
    backward(len, speed);
    delay(del);
  }
}

void detect_obstacle()
{
  turn_to(0);
  forward(250, 200);
  if (get_distance_cm() < 25)
  {
    if (get_Ypos() > 1.25)
    {
    turn_to(-PI/2);
    forward(2000, 200);
    }
    else if(get_Ypos() > .75)
    {
    turn_to(-PI/2);
    forward(2000, 200);
    }
    else if(get_Ypos() != -1) 
    {
    turn_to(PI/2);
    forward(4000, 200);
    } else 
    {
      forward(400, 200);
    }
    
  }
  else
  {
  forward(1500,200);
  }
}

void detect_obstacle2()
{
  turn_to(0);
  forward(250, 200);
  if (get_distance_cm() < 25)
  {
    if (get_Ypos() > 1.25)
    {
    turn_to(-PI/2);
    forward(2000, 200);
    }
    else if(get_Ypos() > .75)
    {
    turn_to(-PI/2);
    forward(2000, 200);
    }
    else if(get_Ypos() != -1) 
    {
    turn_to(PI/2);
    forward(4000, 200);
    } else 
    {
      forward(400, 200);
    }
    
  }
  else
  {
  forward(1500,200);
  }
}






