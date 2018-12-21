#include <stdio.h>
#include "cs136-trace.h"
#include "bisection.h"

// this is a very simple test program
// to illustrate how to call bisection.

double poly_with_root_sqrt2(double x) {
  return x * x - 2;
}

int main(void) {
  printf("%.3f\n", bisection(poly_with_root_sqrt2, 1, 2, 0.0001));
}

