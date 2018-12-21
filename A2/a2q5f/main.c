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

// collatz(void) reads in positive ints and prints the collatz sequence from n
//   to 1
// requires: n >0
// effects: read inputs
//          produce outputs

void collatz(void) {
  int n = read_int();
  while (n != 1) {
    if (n%2 == 1) {
      printf("%d, ", n);
      n = 3*n +1;
    } else {
      printf("%d, ", n);
      n = n/2;
    }
  }
  printf("%d.\n", 1);
}


int main(void) {
  collatz();
  
}