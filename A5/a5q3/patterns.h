// PATTERNS: A module for printing fun patterns

// star_rectangle(height, width) prints out a rectangle of stars
//   of dimension height x width
// requires: height, width >= 0
// effects:  produces output
void star_rectangle(int height, int width);

// star_triangle(height) prints out a triangle of stars the given height
// requires: height >= 0
// effects:  produces output
void star_triangle(int height);

// star_diamond(k) prints a diamond pattern 2 * k - 1 rows high
// requires: k > 0
// effects:  produces output
void star_diamond(int k);

// digit_rectangle(height, width) prints out a rectangle of digits
//   of dimension height x width
// requires: height, width >= 0
// effects:  produces output
void digit_rectangle(int height, int width);

// digit_triangle(height) prints out a triangle of digits the given height
// requires: height >=0
// effects:  produces output
void digit_triangle(int height);
