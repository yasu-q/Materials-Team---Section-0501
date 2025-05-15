// WIFI SETUP
#include "Enes100.h"

// Begin function paratemers. Identification stuff
const char TEAM_NAME[] = "Material ID Team";
const int ARUCO_ID = 817;
const int ROOM_NUMBER = 1120; // 1120 for the main room, 1116 for other

// Pin identifiers
// Wi-fi RX and TX pins
const int WIFI_RX_PIN = 2;
const int WIFI_TX_PIN = 3;

// WIFI SETUP FUNCTION
void wifi_setup() {
  Enes100.begin(TEAM_NAME, MATERIAL, ARUCO_ID, ROOM_NUMBER, WIFI_TX_PIN, WIFI_RX_PIN);
}

// WIFI FUNCTIONS
/*
  Prints the X and Y cords of the OTV & its current heading. Prints a new line after

  Refer to Enes100 for information of what these mean. See top comment
*/
void print_spatial_info() {
  double x_cord = Enes100.getX();
  double y_cord = Enes100.getY();
  double heading = Enes100.getTheta();

  // "Position: (" + x_cord + ", " + y_cord + ") | Heading: " + heading;

  Enes100.print("Position: (");
  Enes100.print(x_cord);
  Enes100.print(", ");
  Enes100.print(y_cord);
  Enes100.print(") | Heading: ");
  Enes100.println(heading);
}
/*
  Wrapper functions
*/
double get_Xpos() {
  return Enes100.getX();
}
double get_Ypos() {
  return Enes100.getY();
}
double get_heading() {
  return Enes100.getTheta();
}
void wifi_println(char message[]) {
  Enes100.println(message);
}
void wifi_print(char message[]) {
  Enes100.print(message);
}

