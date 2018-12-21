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
#include "maze.h"
#include "stack.h"

int main(void) {
  struct maze *a = read_maze();
  int direction = DOWN;
  while(1) {
    if (direction == DOWN) {
       if (is_wall(a, LEFT)) {
         if (is_wall(a, direction)) {
           direction = RIGHT;
           if (is_wall(a, direction)) {
             direction = UP;
             move(a, direction);  
           } else {
             move(a, direction); 
           }
         } else {
           move(a, direction); 
         }
       } else {
         direction = LEFT;
         move(a, direction);
       }
    }
      
    if (direction == RIGHT) {
       if (is_wall(a, DOWN)) {
         if (is_wall(a, direction)) {
           direction = UP;
           if (is_wall(a, direction)) {
             direction = LEFT;
             move(a, direction);  
           } else {
             move(a, direction); 
           }
         } else {
           move(a, direction) ;
         }
       } else {
         direction = DOWN;
         move(a, direction);
       }
    }
    
    if (direction == LEFT) {
       if (is_wall(a, UP)) {
         if (is_wall(a, direction)) {
           direction = DOWN;
           if (is_wall(a, direction)) {
             direction = RIGHT;
             move(a, direction);  
           } else {
             move(a, direction); 
           }
         } else {
           move(a, direction) ;
         }
       } else {
         direction = UP;
         move(a, direction);
       }
    }
    
    if (direction == UP) {
       if (is_wall(a, RIGHT)) {
         if (is_wall(a, direction)) {
           direction = LEFT;
           if (is_wall(a, direction)) {
             direction = DOWN;
             move(a, direction);  
           } else {
             move(a, direction); 
           }
         } else {
           move(a, direction) ;
         }
       } else {
         direction = RIGHT;
         move(a, direction);
       }
    }
  }
}
