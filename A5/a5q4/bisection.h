// a root-finding module

// SEASHELL_READONLY

// bisection(f, lo, hi, tolerance) uses the bisection method to find a root
//   of f that exists between lo and hi such that |f(root)| <= tolerance
// requires: tolerance > 0
//           lo < hi
//           f(lo) * f(hi) < 0
double bisection(double (*f)(double), double lo, double hi, double tolerance);
