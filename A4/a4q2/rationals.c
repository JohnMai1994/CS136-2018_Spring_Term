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
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

///////////////////////////////////
/// DO NOT MODIFY THESE DEFINITIONS:

struct rational {
  int num;
  int den;
};
// requires: den != 0 
//           num, den != INT_MIN


const struct rational INVALID_RATIONAL = {0, 0};


// gcd(a, b) finds the greatest common divisor of a and b
// requires: a, b are non-negative

int gcd(int a, int b) {
  assert(a >= 0);
  assert(b >= 0);
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

///////////////////////////////////

// simplify(r) simplifies a rational based on the requires on assignment
// requires: r.den > 0
struct rational simplify(struct rational r) {
  int cd = gcd(r.num, r.den);
  if (cd == 1) {
    return r;
  } else {
    r.num = r.num/cd;
    r.den = r.den/cd;
  }
  return r;
}

// r_add(a, b) add two rationals together without overflow
// requires: a.den and b.den > 0
struct rational r_add(struct rational a, struct rational b) {
  struct rational c = {0,0};
  struct rational a_sim = simplify(a);
  struct rational b_sim = simplify(b);
  c.num = ((a_sim.num * b_sim.den) + (a_sim.den * b_sim.num));
  c.den = (b_sim.den * a_sim.den);
  return simplify(c);
}

// r_multiply(a,b) multiply two rationals together without overflow
// requires: a.den and b.den > 0
struct rational r_multiply(struct rational a, struct rational b) {
  struct rational c = {0,0};
  struct rational a_sim = simplify(a);
  struct rational b_sim = simplify(b);
  int cd_1 = gcd(a_sim.num, b_sim.den);
  int cd_2 = gcd(b_sim.num, a_sim.den);
  if (cd_1 != 1) {
    a_sim.num = a_sim.num / cd_1;
    b_sim.den = b_sim.den / cd_1;
  }
  if (cd_2 != 1) {
    b_sim.num = b_sim.num / cd_2;
    a_sim.den = a_sim.den / cd_2;
  }
  c.num = a_sim.num * b_sim.num;
  c.den = a_sim.den * b_sim.den;
  return c;
}


bool r_equal(struct rational a, struct rational b) {
  struct rational a_sim = simplify(a);
  struct rational b_sim = simplify(b);
  if ((a_sim.num == b_sim.num) && (a_sim.den == b_sim.den)) {
    return true;
  } else {
    return false;
  }
}


// bonus question:

// can_add(a,b) passed two ints(a, b) and determines if they can be added
//     without causing overflow
// requires:  INT_MIN <= a, b <= INT_MAX 
bool can_add(int a, int b){
  if ((a> 0) && (b >0)){
    return (a <= INT_MAX - b);
  } else if ((a<=0)&&(b<=0)){
    return (a >= INT_MIN - b);
  } else {
    return true;
  }
}

// can_mult(a, b) passed two ints(a,b) and determines if they can be safely 
//    multiplied without causing overflow.
// requires:  INT_MIN <= a, b <= INT_MAX 
bool can_mult(int a, int b){
  if ((a ==0)||(b==0)){
    return true;
  }
  if ((a> 0) && (b > 0)) {
    return (a <= INT_MAX / b);
  } else if ((a<0)&&(b<0))  {
    return (a >= INT_MAX/ b);
  } else if ((a<0)&&(b>0)){
    return (a >= INT_MIN / b); 
  } else{
    return (b >= INT_MIN / a);
  }
}

struct rational safe_r_add(struct rational a, struct rational b) {
  struct rational c = {0,0};
  struct rational a_sim = simplify(a);
  struct rational b_sim = simplify(b);
  
  if (can_mult(a_sim.num, b_sim.den) && can_mult(a_sim.num, b_sim.den)) {
    if (can_add((a_sim.num * b_sim.den), (a_sim.den * b_sim.num))) {
      c.num = ((a_sim.num * b_sim.den) + (a_sim.den * b_sim.num));
    } else {
      return INVALID_RATIONAL;
    }
  } else {
    return INVALID_RATIONAL;
  } 
  
  if (can_mult(b_sim.den, a_sim.den)) {
    c.den = (b_sim.den * a_sim.den);
  } else {
    return INVALID_RATIONAL;
  }
  
  return simplify(c);
}


struct rational safe_r_multiply(struct rational a, struct rational b) {
  struct rational c = {0,0};
  struct rational a_sim = simplify(a);
  struct rational b_sim = simplify(b);
  int cd_1 = gcd(a_sim.num, b_sim.den);
  int cd_2 = gcd(b_sim.num, a_sim.den);
  if (cd_1 != 1) {
    a_sim.num = a_sim.num / cd_1;
    b_sim.den = b_sim.den / cd_1;
  }
  if (cd_2 != 1) {
    b_sim.num = b_sim.num / cd_2;
    a_sim.den = a_sim.den / cd_2;
  }
  if (can_mult(a_sim.num, b_sim.num)){
     c.num = a_sim.num * b_sim.num;
  } else {
    return INVALID_RATIONAL;
  }
  
  if (can_mult(a_sim.den, b_sim.den)){
    c.den = a_sim.den * b_sim.den;
  } else {
    return INVALID_RATIONAL;
  }
  
  return c;
}


int main(void) {
  struct rational quarter = {1, 4};
  struct rational quarter_unsimplified = {4, 16};  
  struct rational half = {1, 2};
  assert(r_equal(quarter, quarter));
  assert(r_equal(quarter, simplify(quarter_unsimplified)));
  assert(r_equal(half, r_add(quarter, quarter)));
  assert(r_equal(quarter, r_multiply(half, half)));
  
  // student tests
  struct rational a = {6, 2};
  struct rational b = {3, 1};
  struct rational c = {36, 6};
  struct rational d = {1, 1};
  struct rational e = {INT_MAX, INT_MAX};
  struct rational f = {1, INT_MAX/3};
  struct rational g = {1, INT_MAX-1};
  struct rational h = {3, 9};
  assert(r_equal(simplify(a), b));
  assert(r_equal(c, r_add(a,b)));
  assert(r_equal(d,e));
  assert(r_equal(g, r_multiply(h, f)));
}
