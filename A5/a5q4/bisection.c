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

#include <stdio.h>
#include "cs136-trace.h"
#include "bisection.h"

// bisection(f, lo, hi, tolerance) uses the bisection method to find a root
//   of f that exists between lo and hi such that |f(root)| <= tolerance
// requires: tolerance > 0
//           lo < hi
//           f(lo) * f(hi) < 0
double bisection(double (*f)(double), double lo, double hi, double tolerance) {
  
  while(1){
    double mid = (lo + hi)/2;
    double target = f(mid);
    if (target < 0) {
      target = -target;
    }
    if (target <= tolerance) {
      return mid;
    } 
    
    if (f(mid) > 0) {
      hi = mid;
    } else if (f(mid) < 0){
      lo = mid;
    }
  }
}
