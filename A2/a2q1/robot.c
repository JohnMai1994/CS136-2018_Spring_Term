/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Jiadong Mai  
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"


int x = 0;
int y = 0;
int direction = 4;
int speed = 1;

// turn_right(void) change the direction to right from the robot is facing 
void turn_right(void) {
  direction += 1;
  return;
}

// turn_left(void) change the direction to left from the robot is facing
void turn_left(void) {
  direction -= 1;
  return;
}

// move(void) changes the position of the robot by moving the current speed
//   in the current direction
void move(void) {
  if (direction%4 == 0) {
    y += speed;
  } else if (direction%4 == 1) {
    x += speed;
  } else if (direction%4 == 2) {
    y -= speed;
  } else {
    x -= speed;
  }
}

// set_speed(n) changes the speed of the robot to be n
// requires: n > 0
void set_speed(int n) {
  assert(n > 0);
  speed = n;
  return;
}

// print_state(void) prints the current state of the robot
void print_state(void) {
  // These strings are provided so you can avoid typos:
  
  // "Position: (%d,%d) | Speed: %d | Direction: "
  // "North\n"
  // "South\n"
  // "East\n"
  // "West\n"
  printf("Position: (%d,%d) | Speed: %d | Direction: ", x, y, speed);
  if (direction%4 == 0) {
    printf("North\n");
  } else if (direction%4 == 1) {
    printf("East\n");
  } else if (direction%4 == 2) {
    printf("South\n");
  } else {
    printf("West\n");
  }
}

int main(void) {
  print_state();
  move();
  turn_right();
  print_state();
  turn_right();
  set_speed(2);  
  print_state();
  turn_left();
  turn_left();
  turn_left();
  move();
  print_state();
  
  // you can add your own tests below and modify simple.expect
  x = 0;
  y = 0;
  direction = 4;
  speed = 1;

  turn_right();
  turn_left();
  set_speed(6);
  turn_left();
  move();
  move();
  turn_left();
  move();
  print_state();
  set_speed(3);
  turn_left();
  move();
  print_state();
  
  
  
  
}
