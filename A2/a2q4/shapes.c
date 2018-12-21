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

// start_row(width) prints out width *'s on a line
// requires: width >= 0
// effects: produces output
void star_row(int width) {
  assert(width>=0);
  while(width>0){
    printf("*");
    --width;
  }
  printf("\n");
}

// star_rectangle(height, width) prints out a rectangle of stars
//    of dimension height x width
// requires: height, width >= 0
// effects: produces output
void star_rectangle(int height, int width) {
  assert(height >= 0);
  assert(width >= 0);
  while (height) {
    star_row(width);
    --height;
  }
}

// star_triangle(height) prints out a triangle of stars the given height
// requires: height >= 0
// effects: produces output
void star_triangle(int height) {
  assert(height >= 0);
  int k = 1;
  while(k <= height) {
    star_row(k);
    ++k;
  }
}

// space_row(n) prints n spaces(without a newline)
// effects: produces outputs
void space_row(int n) {
  while (n) {
    printf(" ");
    --n;
  }}

// star_diamond_countup(row, k) prints a diamond pattern 2*k-1 rows high
// requires: row, k> 0
// effects: produces output
void star_diamond_countup(int row, int k) {
  while (row != k) {
    space_row(k-row);
    star_row((row-1)*2 +1);
    ++row;
  }
  while (row) {
    space_row(k-row);
    star_row((row-1)*2+1);
    --row;
  }    
}

// star_diamond(k) prints a diamond pattern 2*k-1 rows high
// requires: k> 0
// effects: produces output
void star_diamond(int k) {
  assert(k>0);
  star_diamond_countup(1,k);
}

// digit_row_countup(digit, i, n) prints a total of (n-i+1) digits
//   followed by a newline, starting with the digit "digit"
// effects: produces output
void digit_row_countup(int digit, int i, int n){
  while (i <= n) {
    printf("%d", digit%10);
    ++digit;
    ++i;
  }
  printf("\n");
}


// digit_rectangle_countup(row, height, width) prints rows row height
//   of the rectangle from digit_rectangle
// effects: produces output
void digit_rectangle_countup(int row, int height, int width) {
  while (row <= height){
    digit_row_countup(row, 1, width);
    ++row;
  }
}

// digit_rectangle(height, width) prints out a rectangle of digits
//    of dimension height x width
// requires: height, width >= 0
// effects: produces output
void digit_rectangle(int height, int width) {
  assert(height >=0);
  assert(width>=0);
  digit_rectangle_countup(1, height, width);
}


// digit_triangle_countup(row, height) prints rows row.. height
//   of the triangle from digit_triangle
// effects: produces output
void digit_triangle_countup(int row, int height){
  while (row <= height) {
    digit_row_countup(row, 1,row);
    ++row;
  }
}

// digit_triangle(height) prints out a triangle of digits the given height
// requires: height >= 0
// effects: produces output
void digit_triangle(int height) {
  assert(height >= 0);
  digit_triangle_countup(1, height);

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
