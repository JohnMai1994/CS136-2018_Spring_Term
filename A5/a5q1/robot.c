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

#include "cs136-trace.h"
#include <stdbool.h>
#include <stdio.h>

///////////////////////////////////////////////
///////////////////////////////////////////////
// DO NOT MODIFY THESE DEFINITIONS

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

struct robot {
  int x;
  int y;
  int direction;
  int speed;
};
// requires: speed > 0
//           direction is one of: NORTH, EAST, SOUTH, WEST

///////////////////////////////////////////////
///////////////////////////////////////////////
// ONLY MODIFY read_command

// read_command(r) control the robot through reading the input and mutate
//      the situation of the robot
// requires: speed > 0
//           direction is one of: NORTH, EAST, SOUTH, WEST
// effects: mutate *r
//          print outputs

bool read_command(struct robot *r) {
  const int print = lookup_symbol("print");
  const int left = lookup_symbol("left"); 
  const int right = lookup_symbol("right");
  const int move = lookup_symbol("move");
  const int speed = lookup_symbol("speed"); 
  const int quit = lookup_symbol("quit");

  int command = read_symbol();
  
  if (command == right) {
    r->direction += 1;
    return 1;
  }
  
  if (command == left) {
    r->direction -= 1;
    return 1;
  }
  
  if (command == print) {
    printf("Position: (%d,%d) | Speed: %d | Direction: ", 
           r->x, r->y, r->speed);  
    if (r->direction%4 == 0) {
      printf("North\n");
    } else if (r->direction%4 == 1) {
      printf("East\n");
    } else if (r->direction%4 == 2) {
      printf("South\n");
    } else {
      printf("West\n");  
    }
    return 1;
  }
  
  if (command == move) {
    if (r->direction%4 == 0) {
      r->y += r->speed;
    } else if (r->direction%4 == 1) {
      r->x += r->speed;
    } else if (r->direction%4 == 2) {
      r->y -= r->speed;
    } else {
      r->x -= r->speed;
    }
    return 1;
  }
  
  if (command == speed) {
    int sp;
    scanf("%d",&sp);
    r->speed = sp;
    return 1;
  }
  
  if (command == quit) {
    printf("Goodbye\n");
    return false;
  }
  
  return false;

}


// THERE IS NO REASON TO MODIFY THIS MAIN FUNCTION

int main(void) {
  struct robot r = {0, 0, 0, 1};
  while (read_command(&r));
}
