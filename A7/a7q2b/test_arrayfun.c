#include <assert.h>
#include <stdio.h>
#include "arrayfun.h"

// A simple assertion-based client for arrayfun

int main(void) {
  int len = 3;
  int a[3] = {1, 2, 3};
  int b[3] = {3, 1, 2};

  assert(max_diff(a, len) == 2);

  assert(consec_sum(a, len, b, len));

  even_first(a, len);
  assert(a[0] == 2);
  assert(a[1] == 1 || a[2] == 1);
  assert(a[1] == 3 || a[2] == 3);
}
