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
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>


const double EPSILON = 0.01;

// dabs(x) returns the absolute value of x
static double dabs(double n){
  if (n < 0) {
    return -n;
  }
  return n;
}

// mean(a, len) returns the mean of the elements of the array a
// requires: a[] is vaild
//           len >=0
static int sum(const int a[], int len) {
  assert(a);
  assert(len>0);
  int s = 0;
  for (int i = 0; i < len;++i) {
    s+= a[i];
  }
  return s;
}

double mean(const int a[], int len) {
  // Your code goes here
  assert(a);
  assert(len>0);
  int s = sum(a, len);
  return (1.0*s)/len;
}

// var(a, len) returns the variance of the elements of the array a
// requires: a[] is vaild
//           len >= 0
double var(const int a[], int len) {
  // Your code goes here
  assert(a);
  assert(len>0);
  int sqr_sum = 0;
  int count = 0;
  for (int i =0; i< len; ++i) {
    sqr_sum += a[i] * a[i];
    count += 1;
  }
  int mean_num = mean(a, len)*mean(a, len);
  int variance = sqr_sum/count - mean_num;
  return variance;
}


int main(void) {
  int a[2] = {2, 2};
  assert(dabs(mean(a, 2) - 2) < EPSILON);
  assert(dabs(var(a, 2)) < EPSILON);
  trace_int((mean(a,2)-541.5000) < EPSILON);
}
