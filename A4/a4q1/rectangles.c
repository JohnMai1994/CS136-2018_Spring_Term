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

struct point {
  int x;
  int y;
};

// rectangles are axis-aligned
struct rectangle {
  struct point ll;              // lower-left corner
  struct point ur;              // upper-right corner
};

const struct rectangle NO_OVERLAP = {{0, 0}, {0, 0}};
///////////////////////////////////


// valid_rectangle(c) determine whether the rectangle is valid rectangle by 
//   comparing their lower-left and upper-right
bool valid_rectangle(struct rectangle r) {
  if ((r.ll.x < r.ur.y) && (r.ll.y < r.ur.y)) {
    return true;
  } else {
    return false;
  }
}

// equal_rectangles(r1, r2) determine whether two rectangles is same size and
//    in the same location
// requires: r1 and r2 are valid rectangles
bool equal_rectangles(struct rectangle r1, struct rectangle r2) {
  if ((r1.ll.x == r2.ll.x) && (r1.ll.y == r2.ll.y) && 
      (r1.ur.x == r2.ur.x) && (r1.ur.y == r2.ur.y)){
    return true;
  } else {
    return false;
  } 
}

// overlap(r1, r2) return NO_overlap if two rectangles doesnot overlaps,
//    else, return the rectangle that these two rectangles overlap
// requires: r1 and r2 are valid rectangles
struct rectangle overlap(struct rectangle r1, struct rectangle r2) {
  struct rectangle c = {{0,0}, {0,0}};
  
  if ((r1.ll.x < r2.ur.x) && (r1.ll.y < r2.ur.y) &&
      (r2.ll.x < r1.ur.x) && (r2.ll.y < r1.ur.y)) {
    if (r1.ll.x > r2.ll.x) {
      c.ll.x = r1.ll.x;
    } else {
      c.ll.x = r2.ll.x;
    }
    if (r1.ll.y > r2.ll.y) {
      c.ll.y = r1.ll.y;
    } else {
      c.ll.y = r2.ll.y;
    }
    if (r1.ur.x > r2.ur.x) {
      c.ur.x = r1.ur.x;
    } else {
      c.ur.x = r2.ur.x;
    }
    if (r1.ur.y > r2.ur.y) {
      c.ur.y = r1.ur.y;
    } else {
      c.ur.y = r2.ur.y;
    }
    return c;
  } else {
    return NO_OVERLAP;
  }
}

// rotate_right(r) returns the rectangle that is the 90 degrees clockwise around
//   the origin(0,0)
// requires: r1 and r2 are valid rectangles
struct rectangle rotate_right(struct rectangle r) {
  struct rectangle c = r;
  
  r.ll.x = c.ll.y;
  r.ll.y = -c.ur.x;
  r.ur.x = c.ur.y;
  r.ur.y = -c.ll.x;
  return r;
}


int main(void) {

  struct rectangle a = {{0, 0}, {1, 1}};
  struct rectangle b = {{0, -1}, {1, 0}};
  
  rotate_right(a);
  assert(valid_rectangle(a));
  assert(equal_rectangles(a, a));
  assert(equal_rectangles(a, overlap(a, a)));
  assert(equal_rectangles(NO_OVERLAP, overlap(a, b)));
  assert(equal_rectangles(b, rotate_right(a)));
  assert(equal_rectangles(a, rotate_right(rotate_right(
    rotate_right(rotate_right(a))))));
  
  // student tests
  struct rectangle c = {{0,0}, {-1,-1}};
  struct rectangle d = {{0,0}, {0,0}};
  struct rectangle e = {{0,0}, {1,1}};
  struct rectangle f = {{-1,-1}, {1,1}};
  
  assert(valid_rectangle(c) == 0);
  assert(valid_rectangle(d) == 0);
  assert(equal_rectangles(a, e));
  assert(equal_rectangles(a, overlap(a, f)));
  assert(equal_rectangles(f, rotate_right(f)));
  assert(equal_rectangles(rotate_right(b), rotate_right(rotate_right(e))));
}
