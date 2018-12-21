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
#include "mergesort.h"
#include "select.h"
#include <assert.h>
#include <limits.h>


int select_1(const int a[], int len, int k) {
  assert(a);
  assert(len>0);
  assert(0<=k<len);
  
  int mini = a[0];
  for (int i= 0; i<len; ++i){
    if (a[i] < mini) {
      mini = a[i]; 
    }
  }
  
  for (int runtime = 0; runtime < k; ++runtime){
    int sec_mini = INT_MAX;
    for (int b = 0; b< len; ++b) {
      if((a[b] > mini)&&(a[b] < sec_mini)) {
        sec_mini = a[b]; 
      }
    }
    mini = sec_mini;
  }
  return mini;
}


int select_2(int a[], int len, int k) {
  assert(a);
  assert(len>0);
  assert(0<=k<len);
  merge_sort(a,len);
  return a[k];
}

int select_3_helper(int a[],int low, int high) {
  int point = a[high];
  int i = (low -1);
  for (int j = low; j <= high-1; ++j) {
     if (a[j] <= point) {
       ++i;
       int tmp = a[i];
       a[i] = a[j];
       a[j] = tmp;
     }
  }
  int tmp = a[i+1];
  a[i+1] = a[high];
  a[high] = tmp;
  return (i + 1);
}

// include your time: analysis here
// the best runtime is O(n), if every pilot that we are looking for is in
//  the middle of the array,and the rest of middle , n + n/2 + n/4+ n/8....= 
//  2n = O(n)
// the worst runtime is O(n^2), if every pilot is in the decreasing order, 
//   and each select with only one element. therefore, the runtime n + n-1 +
//   n-2 +.... = O(n^2)
// the average runtime is O(nlogn), T(n) = n + 2T(n/2) = O(nlogn)
int select_3(int a[], int len, int k) {
  assert(a);
  assert(len>0);
  assert(0<k < len);
  int position = select_3_helper(a, 0, len-1);
  int result = 0;
  if (position == k) {
    result = a[k];
  } else if (position < k) {
    return select_3((a + position+1), len-position-1 , k-position-1);
  } else {
    return select_3(a, position, k);
  }  
  trace_int(result)
  return result;
}
