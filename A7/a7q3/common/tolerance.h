// SEASHELL_READONLY

#include <stdbool.h>

// A module for testing programs with floating point

// within_tolerance(a, b, tolerance) determines if the absolute difference
//   between a and b is less than or equal to the tolerance
// requires: tolerance >= 0
bool within_tolerance(double a, double b, double tolerance);
