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


// sequence(void) reads in ints and outputs a sequence of all integers start
//   from 0 to n
// requires: n>=0
// effects: read inputs
//          produce outputs
void sequence(void){
  int n = read_int();
  int k = 0;
  while (k < n) {
    printf("%d, ", k);
    ++k;
  }
  printf("%d.\n", n);
}


int main(void) {
  sequence();
}