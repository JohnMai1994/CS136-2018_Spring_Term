#include <assert.h>
#include <stdio.h>
#include "expt.h"
#include "tolerance.h"

// a simple test client for expt

// slow_expt(x, n) computes x^n using a simple method
// requires: n >= 0
// time: O(n)
double slow_expt(const double x, const int n) {
  assert(n >= 0);
  if (n == 0) return 1;
  return x * slow_expt(x, n - 1);
}

// test_expt(x, n) asserts that slow_expt(x, n) & fast_expt(x, n)
//   return the same values
void test_expt(const double x, const int n) {
  assert(within_tolerance(slow_expt(x, n), fast_expt(x, n), 0.1));
}

int main(void) {
  test_expt(2, 2);
}
