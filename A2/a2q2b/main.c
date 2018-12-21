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



// print_count(count) reads in ints and prints the numbers in reverse order by
//     adding the count to each number
// effects: read inputs
//          prints numbers 
int print_count(int count) {
  int n = read_int();
  if (n == READ_INT_FAIL) {
    return count;
  } else{
    ++count;
    int total_count = print_count(count);
    printf("%d\n", n+total_count);
    return total_count;
  }
}





int main(void) {
   print_count(0);
   return 0;
}
