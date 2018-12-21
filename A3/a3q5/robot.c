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


struct robot {
  int x;
  int y;
  int direction;
  int speed;
};

// main() control the robot through reading the input and mutate the situation
//     of the robot
// effects: read inputs
//          print outputs
int main(void) {
  struct robot begin = {0,0,4,1};
  
  while (1) {
    const int QUIT = lookup_symbol("quit");
    int symb = read_symbol();
    if (symb == QUIT) {
      printf("Goodbye\n");
      break;
    }
    
    if (symb == lookup_symbol("print")) {
      printf("Position: (%d,%d) | Speed: %d | Direction: ", 
             begin.x, begin.y, begin.speed);
      if (begin.direction%4 == 0) {
        printf("North\n");
      } else if (begin.direction%4 == 1) {
        printf("East\n");
      } else if (begin.direction%4 == 2) {
        printf("South\n");
      } else {
        printf("West\n");
      }
    } else if (symb == lookup_symbol("move")) {
      if (begin.direction%4 == 0) {
        begin.y += begin.speed;
      } else if (begin.direction%4 == 1) {
        begin.x += begin.speed;
      } else if (begin.direction%4 == 2) {
        begin.y -= begin.speed;
      } else {
        begin.x -= begin.speed;
      }  
    } else if (symb == lookup_symbol("left")) {
      begin.direction -= 1;
    } else if (symb == lookup_symbol("right")) {
      begin.direction += 1;
    } else if (symb == lookup_symbol("speed")) {
      int n = read_int();
      begin.speed = n;
    } 
  }
}
