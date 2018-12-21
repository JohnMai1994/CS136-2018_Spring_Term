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

#include "cs136-trace.h"
#include <assert.h>

// bubble_sort(a, len) mutate the array a by sorting it.
// requires: a[] is vaild
//           len>=0
// effects: a have been mutated
void bubble_sort(int a[], int len) {
  assert(a);
  assert(len>0);
  for (int i = 0; i< len; ++i) {
    for (int j = i+1; j<len; ++j) {
      if (a[i] > a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
}
   
  
// median(a, len) returns the median element of the array
// requires: a[] is vaild
//           len>=0
// effects: a have been mutated
int median(int a[], int len) {
  // Your code goes here
  bubble_sort(a,len);
  if (len%2) {
    return a[len/2];
  } else {
    return (a[len/2] + a[len/2-1])/2;
  }
}

int main(void) {
  int a[5] = {5, 5, 5, 5, 5};
  assert(median(a,5) == 5);
  
  int b[10] = {4,5,2,1,8,3,4,5,1,2};
  assert(median(b,10) == 3);
}
