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

// big_small() read inputs and prints the difference betweence the largest num
//   and the smallest num. if only one input, it print "0\n"
// effects: read input
//          produce output
void big_small(void){
  int n = read_int();
  int smallest = n;
  int biggest = n;
  
  while (1) {
    n = read_int();
    if (n == READ_INT_FAIL) {
      break;
    } else if (n < smallest){
      smallest = n;
    } else if (n > biggest) {
      biggest = n;
    }
  }
  printf("%d\n", biggest - smallest);
}

int main(void) {
  big_small();
}