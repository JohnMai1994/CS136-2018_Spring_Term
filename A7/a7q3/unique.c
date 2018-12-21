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
#include "unique.h"
#include <assert.h>
#include "mergesort.h"



bool distinct(int a[], int len) {
  assert(a);
  assert(len);
	merge_sort(a, len);
  for (int i = 0; i < len-1; ++i){
    if (a[i] == a[i+1]) {
      return false;
    }
  }
  return true;
}



bool distinct_range(const int a[], int len) {
  // ADDITIONAL CONSTRAINTS:
  //   * You may only loop through array a ONCE
  //   * You may define a local array of size 10000
  assert(a);
  assert(len > 0);
  int b[10000] = {0};
  for (int i = 0; i < len; ++i) {
    b[a[i]] += 1;
  }
  for (int k = 0; k < 10000; ++k) {
    if (b[k] == 2) {
      return false;
    }
  }
	return true;
}



int missing(const int a[], int n) {
  // ADDITIONAL CONSTRAINTS:
  //   * You may only loop through array a ONCE
  //   * You may NOT define a local array
  assert(a);
  assert(n > 0);
  int sum = 0;
  sum = sum + n;
	for (int k = 0; k < n-1; ++k){
    sum += k;
    sum -= a[k];
  }
  sum = sum + n-1;
  return sum;
}
