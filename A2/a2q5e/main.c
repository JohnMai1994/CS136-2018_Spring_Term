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

// sequence_double(first_num) reads in pairs of ints(a, b) and prints a
//    a sequence of all integers from a to b
// requires: b>= a>= 0
// effests: read inputs
 //         produces outputs
void sequence_double(int first_num){
  int second_num = read_int();
  while (first_num < second_num) {
    printf("%d, ", first_num);
    ++first_num;
  }
  printf("%d.\n", second_num);
}

int main(void) {
  int first_number = read_int();
  sequence_double(first_number);
  return 0 ;
}