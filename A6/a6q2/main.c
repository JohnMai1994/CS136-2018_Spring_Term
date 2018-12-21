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
#include "array-eq.h"
#include <assert.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubble_sort(int a[], int len) {
  assert(a);
  assert(len>0);
  int i, j;
  int times_swap =0;
  for (i = 0; i < len-1; i++)      {
      for (j = 0; j < len-i-1; j++) {
         if (a[j] > a[j+1]){
           swap(&a[j], &a[j+1]);
           ++times_swap;
         }
       }
  }
  return times_swap;
}
 

int main(void) {
  int input[5] = {5, 4, 3, 2, 1};
  int sorted[5] = {1, 2, 3, 4, 5};
  assert(bubble_sort(input,5) == 10);
  assert(array_equal(input,sorted,5));
}
 
