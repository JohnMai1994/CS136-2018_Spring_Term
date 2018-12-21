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

// reverse_digits(n) produce the number at the reverse order of n
// requires: n >= 0
int reverse_digits(int n) {
  int remainder = 0;
  int reversedigits = 0;
  while (n!=0) {
    remainder = n%10;
    reversedigits = reversedigits*10 + remainder;
    n = n/10;
  }
  return reversedigits;
}

// replace_star(void) reads in ints and prints n followed by a newline but the 
//    the digit 3 was insteaded by a star(*)
// effects: read inputs
//          produce outputs
void replace_star(void){
  while (1){
    int n = read_int();
    if (n == READ_INT_FAIL){
      break;
    }
    n = reverse_digits(n);
    
    while (n != 0){
    if (n%10 != 3) {
      printf("%d", n%10);
    } else {
      printf("*");
    }
    n /= 10;
  }
     printf("\n"); 
  }
}
    
    
int main(void) {
  replace_star();
}