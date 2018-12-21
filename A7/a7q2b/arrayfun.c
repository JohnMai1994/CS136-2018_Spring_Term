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

#include "arrayfun.h"
#include "cs136-trace.h"
#include <assert.h>
  
int max_diff(const int a[], int len) {
  assert(a);
  assert(len>0);
	int min = a[0];
  int max = a[0];
  for (int i = 1; i< len; ++i){
    if (a[i] < min){
      min = a[i];
    }
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max-min;
}	


bool consec_sum(const int a[], int n, const int b[], int m) {
	assert(a);
  assert(b);
  assert(n>0);
  assert(m>0);
  for (int k = 0; k< m; ++k){
    int start = 0;
    int end = n-1;
    for (int middle = (start+end)/2; middle>0 ; middle /= 2) {
      
      if ((b[k] == a[middle] + a[middle+1])||
          (b[k] == a[middle] + a[middle-1])){
        return true;
      }
      if (b[k] > a[middle] + a[middle+1]) {
        start = middle+1;
      } else{
        end = middle-1;
      }
    }
  }
  return false;
}


void even_first(int a[], int len) {
  assert(a);
  assert(len>0);
  int count = 0;
  for (int i = 0; i < len; ++i){
    if (a[i]%2== 0) {
      int tmp = a[count];
      a[count] = a[i];
      a[i] = tmp;
      ++count;
    }
  }
}
