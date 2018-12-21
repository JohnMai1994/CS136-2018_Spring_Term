#include <stdbool.h>

// distinct(a, len) determines if all elements of a are distinct
// requires: a is a valid array with len elements
// effects:  a may be modified
// time:     O(nlogn)
bool distinct(int a[], int len);

// distinct_range(a, len) determines if all elements of a are distinct
// requires: a is a valid array with len elements
//			     every element of a is in the range [1, len]
// time:     O(n)
bool distinct_range(const int a[], int len);

// missing(a, n) returns the number in the range [1,n] that is
//   missing from array a 
// requires: a is a valid array with n - 1 elements
// 			     exactly one number in the range [1,n]
//			     is missing from a
// time:     O(n)
int missing(const int a[], int n);
