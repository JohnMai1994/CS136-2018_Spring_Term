#include <stdbool.h>

// max_diff(a, len) finds the maximum difference between two elements in a
// time: O(n)
int max_diff(const int a[], int len);


// consec_sum(a, n, b, m) determines if an element of b is the sum
//   of any two consecutive elements in a
// requires: a and b are arrays of length n and m respectively
// 			     a is sorted in increasing order (b may not be sorted)
// time:     O(m*logn), n is len of a and m is len of b
bool consec_sum(const int a[], int n, const int b[], int m);


// even_first(a, len) puts all the even numbers before all of the odd numbers
//   in the array a
// effects: modifies a
// time:    O(n)
void even_first(int a[], int len);
