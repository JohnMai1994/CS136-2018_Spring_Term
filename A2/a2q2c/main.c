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

// mini(min_so_far) reads in ints, and prints the numbers in reverse order by
//    subtracting the smallest number from each number
// effect: read input
//         produce output
int mini(int min_so_far){
  int n = read_int();
  int smallest = min_so_far;
  if (n != READ_INT_FAIL) {
    if (n < smallest) {
      smallest = n;
    } 
    int actual_min = mini(smallest);
    printf("%d\n", n-actual_min);
    return actual_min;
  } 
  
  return smallest;
}

int main(void) {
  int first_number = read_int();
  int miniment = mini(first_number);
  printf("%d\n", first_number - miniment);
  return 0 ;
}
