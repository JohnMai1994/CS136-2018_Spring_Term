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
#include "tolerance.h"
#include "expt.h"

// find_log(n,b,tolerance) return the values which its absolute difference 
//       between tolerance
// requires: n>0, b>1, and tolerance >= 0
double find_log(double n, double b, double tolerance) {
  double x_k1;
  double x_k0 = 1;
  while (1){
    if (within_tolerance(n, expt(b, x_k0), tolerance)) {
      return x_k0;
      break;
    } else {
      x_k1 = x_k0 - (expt(b, x_k0) - n)/ (expt(b, x_k0));
      x_k0 = x_k1;
    }
  }
  
}
    


const double test_tolerance = 0.001;

// test_log(n, b) finds_log(n,b) and asserts that 
//                b to the power of the result is within test_tolerance of n.
// effects: displays a message for visual testing
void test_log(double n, double b) {
  double result = find_log(n, b, test_tolerance);
  printf("the log of %f base %f is approximately %.3f\n", n, b, result);
  assert(within_tolerance(n, expt(b, result), test_tolerance));
}

int main(void) {
  test_log(9,2.5);
  test_log(5.5,2);
  
  test_log(3,2);
  test_log(8,3);
    
}

