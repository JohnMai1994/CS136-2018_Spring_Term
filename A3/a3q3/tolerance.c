#include <assert.h>
#include "tolerance.h"

// SEASHELL_READONLY

// see tolerance.h

bool within_tolerance(double a, double b, double tolerance) {
  assert(tolerance >= 0);
  if (a < b) {
    return (b - a) <= tolerance;
  } else {
    return (a - b) <= tolerance;
  }
}
