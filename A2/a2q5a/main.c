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


// main() prints number that are greater than any of the preceding numbers.
// effects: read input
//          produce output
void raise_order(void) {
  int first_num = read_int();
  printf("%d\n", first_num);  
  int bigger_num = first_num;
  
  while (1) {
    int n = read_int();
    if (n == READ_INT_FAIL) {
      break;
    } else if (n > bigger_num) {
      bigger_num = n;
      printf("%d\n", bigger_num);
    }
  }
}

int main(void) {
  raise_order();
}
  
  
