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
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////

// star_row(width) prints out width stars
// requires : width >= 0
void star_row(int width) {
  if (width == 1) {
    printf("*\n");
  } else {
    printf("*");
    star_row(width-1);
  }
}

// star_rectangle(height, width) prints out height rows of stars, 
//    and each row is width long
// requires: width and height >= 0
void star_rectangle(int height, int width) {
  if (height == 1) {
    star_row(width);
    printf("\n");
  } else {
    star_row(width);
    star_rectangle(height-1, width);
  }
}




// star_triangle(height) prints out height rows of stars, each row is i long
//  requires: height >= 0
void star_triangle(int height) {
  if (height == 1) {
    star_row(height);
  } else {
    star_triangle(height-1);
    star_row(height);
  } 
}

void star_triangle_anti(int height) {
  if (height == 1) {
    star_row(height);
  } else {
    star_row(height);
    star_triangle_anti(height-1);
  }
}

// star_diamond(k) prints out (2k-1) rows of stars,
//  k > 0
void star_diamond(int k) {
  star_triangle(k);
  star_triangle_anti(k-1);
}



// digit_rectangle(height, width) prints stars, digits arre printed
// requires: height and width >= 0
void digit_rectangle(int height, int width) {
  
}

// digit_triangle(height) is similar to star_triangle, but follows the same \
//   rules as digit_rectangle. 
// requires: height >= 0
void digit_triangle(int height) {
}


// IMPORTANT:
// In our "testing function" (main)
// we have added an extra newline (\n) between tests
// however, your functions should not print the extra newline

int main(void) {
  star_row(5);
  printf("\n");
  star_rectangle(3, 12);
  printf("\n");
  star_triangle(4);
  printf("\n");
  star_diamond(3);
  printf("\n");
  digit_rectangle(3, 12);
  printf("\n");
  digit_triangle(4);
  // you can add more tests below
  // and modify your simple.expect file
}
