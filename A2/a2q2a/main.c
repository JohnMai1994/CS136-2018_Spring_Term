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


// main() reads in intS, and output the numbers in the original order and 
//    then in reverse order
// effects: reads inpu
//          output messages

int main(void) {
  int n = read_int();
  if (n == READ_INT_FAIL) {
    printf("");
  } else {
    printf("%d\n", n);
    main();
    printf("%d\n", n);
  }  
}
