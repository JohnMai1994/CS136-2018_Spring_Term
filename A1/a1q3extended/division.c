#include "cs136.h"

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
// login ID: 20557203
/////////////////////////////////////////////////////////////////////////////

// away_div(num, denom) return the result of integer division, rounding away
//   from zero, by passing num and denom
// require: denom not equal to 0
int away_div(int num, int denom) {
  if (num % denom > 0) {
    return 1 + (num/denom);
  } else {
    return num/denom;
  }
}

// closest_div(num, denom) return the result of integer division, rounding 
//   toward closest integer, by passing num and denom
// require: denom not equal to 0
int closest_div(int num, int denom) {
  if (denom >= 2* (num % denom)) {
    return num/denom;
  } else {
    return 1 + num/denom;
  }
}

// num_pizzas(num_people, slices_per_pizza, slices_each) return how many whole  
//    pizzas are required to feed by passing num_people, slices_per_pizza, and 
//    slices_each
// requires: num_people, slices_per_pizza, slices_each >= 0
int num_pizzas(int num_people, int slices_per_pizza, int slices_each) {
  return away_div(num_people*slices_each, slices_per_pizza);
}

// necklace(packet_size, colours, length, beads_per_inch) return how many 
//   packets of beads are required to make a necklace, by pass the packe_size
//   , colours, length and beads_per_inch
// requires: packet_size, colours, length, beads_per_inch >= 0
int necklace(int packet_size, int colours, int length, int beads_per_inch) {
  if (packet_size >= away_div(length*beads_per_inch,colours)) {
    return (colours * away_div(away_div(length*beads_per_inch,colours),packet_size));
  } else {
    return (colours * away_div(away_div(length*beads_per_inch,colours),packet_size)) - 
      (colours - length* beads_per_inch%colours);
  }
}


int main(void) {
  assert(away_div(39, 10) == 4);
  assert(closest_div(36, 10) == 4);
  assert(num_pizzas(41, 10, 1) == 5);
  assert(necklace(50, 4, 7, 10) == 4);
  // add more asserts below to test your code
  //away_div
  assert(away_div(41, 10) == 5);
  assert(away_div(0, 10) == 0);
  assert(away_div(-1, 5) == 0);
  assert(away_div(-32, 10) == -3);
  //closest_div
  assert(closest_div(41, 10) == 4);
  assert(closest_div(45, 10) == 4);
  assert(closest_div(49, 10) == 5);
  assert(closest_div(0, 10) == 0);
  assert(closest_div(-35, 10) == -3);
  assert(closest_div(-31, 10) == -3);
  //num_pizzas
  assert(num_pizzas(41, 10, 1) == 5);
  assert(num_pizzas(41, 10, 2) == 9);
  assert(num_pizzas(41, 2, 2) == 41);
  assert(num_pizzas(41, 10, 1) == 5);
  // necklace
   assert(necklace(50, 4, 7, 10) == 4);
   assert(necklace(17, 4, 7, 10) == 6);
   assert(necklace(18, 4, 7, 10) == 4);
}
