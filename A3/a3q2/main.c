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

// can_add(a,b) passed two ints(a, b) and determines if they can be added
//     without causing overflow
// requires:  INT_MIN <= a, b <= INT_MAX 
bool can_add(int a, int b){
  if ((a> 0) && (b >0)){
    return (a <= INT_MAX - b);
  } else if ((a<=0)&&(b<=0)){
    return (a >= INT_MIN - b);
  } else {
    return true;
  }}

// can_mult(a, b) passed two ints(a,b) and determines if they can be safely 
//    multiplied without causing overflow.
// requires:  INT_MIN <= a, b <= INT_MAX 
bool can_mult(int a, int b){
  if ((a ==0)||(b==0)){
    return true;
  }
  if ((a> 0) && (b > 0)) {
    return (a <= INT_MAX / b);
  } else if ((a<0)&&(b<0))  {
    return (a >= INT_MAX/ b);
  } else if ((a<0)&&(b>0)){
    return (a >= INT_MIN / b); 
  } else{
    return (b >= INT_MIN / a);
  }
}

// average3(a,b,c) is passed three non-negative ints(a,b,c) and returns the 
//     int average. avoid overflow during operation
// requires: 0 <= a, b, c <= INT_MAX 
int average3(int a, int b, int c){
  if ((a%3 + b%3 + c%3) < 3) {
    return (a/3 + b/3 + c/3);
  } else {
    return (a/3 + b/3 + c/3) + 1;
  }
}

int main(void) {
  // Uncomment these assertions for the simple tests
  assert(can_add(1,2));
  assert(can_add(2000000000,1000000000) == 0);
  assert(can_add(INT_MAX,INT_MAX) == 0);
  assert(can_add(INT_MIN,INT_MIN) == 0);
  assert(can_add(-1000000000,-1000000000));
  
  assert(can_mult(3,4));
  assert(can_mult(INT_MAX, INT_MIN) == 0);
  assert(can_mult(INT_MAX, INT_MAX) == 0);
  assert(can_mult(1000234, 123480984) == 0);
  assert(can_mult(INT_MIN, -1) == 0);
  assert(can_mult(INT_MIN, 1) == 1);
  assert(can_mult(INT_MAX, -1) == 1);
  assert(can_mult(INT_MAX, 1) == 1);
  
  assert(average3(5, 6, 6) == 5); 
  assert(average3(INT_MAX,INT_MAX,INT_MAX) == INT_MAX);
  assert(average3(2000000001,1000000002,1000000000) == 1333333334); 
  assert(average3(0,1,3)==1);
  
}  
