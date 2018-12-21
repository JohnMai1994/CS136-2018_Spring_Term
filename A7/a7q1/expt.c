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
// login ID: J4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136-trace.h"
#include "expt.h"
#include <assert.h>
   

double fast_expt(double x, int n) {
  assert(n >= 0);
  double acc;
  if (n == 0) {
    return 1;
  }
  acc = fast_expt(x, n/2);
  if (n%2 == 0) {
    return acc*acc;
  } else {
    if (n > 0) {
      return x * acc *acc;
    } else {
      return (acc*acc)/x;
    }
  }
}
