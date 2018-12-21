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
#include <assert.h>

struct statistics {
  int min;
  int max;
  int sum;
};

// stats(a,len, s) mutates the s so that the maximum, minimum and sum fields are
//   equal to the maximum, minimum and sum of the array elements in a.
// requires: a is vaild
//           len >= 0
//  effects: s have been mutated
void stats(const int *a, int len, struct statistics *s){
  // Your code goes here
  assert(a);
  assert(len>0);
  int min = *a;
  int max = *a;
  int sum = 0;
  for (const int *p = a; p < a+len; ++p) {
    if (*p > max) {
      max = *p;
    }
    if (*p < min) {
      min = *p;
    }
    sum += *p;
  }
  s->min = min;
  s->max = max;
  s->sum = sum;
}


int main(void) {
  int a[2] = {2, 2};
  struct statistics s = {};
  stats(a, 2, &s);
  assert(s.min == 2);
  assert(s.max == 2);
  assert(s.sum == 4);
  
  int b[6] = {2, 2,1,6,4,0};
  struct statistics k = {};
  stats(b, 6, &k);
  assert(k.min == 0);
  assert(k.max == 6);
  assert(k.sum == 15);
}
