#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayfun.h"

// see arrayfun.h for documentation

int max_diff(const int a[], int len) {
  assert(a);
  assert(len > 0);
  // note: if len == 1, returns 0
  int diff = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (abs(a[j] - a[i]) > diff) {
        diff = abs(a[j] - a[i]);
      }
    }
  }
  return diff;
} 


bool consec_sum(const int a[], int n, const int b[], int m) {
  assert(a);
  assert(n > 0);
  // note: does not assert that a is sorted
  assert(b);
  assert(m > 0);
  // note: if n == 1, returns false
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n - 1; ++i) {
      if (b[j] == a[i] + a[i + 1]) {
        return true;
      }
    }
  }
  return false;
}


void even_first(int a[], int len) {
  assert(a);
  assert(len > 0);
  
  int temp = 0;
  for (int i = 0; i < len; ++i) {
    if (a[i] % 2 == 0) {
      temp = a[i];
      for (int j = i; j > 0; --j) {
        a[j] = a[j - 1];
      }
      a[0] = temp;
    }
  }
}
