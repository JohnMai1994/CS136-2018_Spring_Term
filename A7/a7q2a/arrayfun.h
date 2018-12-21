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
// login ID: J4mai
/////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>

// max_diff(a, len) finds the maximum difference between two elements in a
// time: O(n^2)
// the inner loop of max_diff(a, len) is O(n-i), which is O(n), because  
//    (j = i + 1; j < len; ++j). the Outer Loop is n times, because 
//    (i = 0; i < len; ++i), therefore, T(n) = n * O(n) = O(n^2)
int max_diff(const int a[], int len);


// consec_sum(a, n, b, m) determines if an element of b is the sum
//   of any two consecutive elements in a
// requires: a and b are arrays of length n and m respectively
// 			     a is sorted in increasing order (b may not be sorted)
// time:     O(m*n)
// the inner loop of consec_sum(a,n,b,m) is O(n), (i = 0; i < n - 1; ++i). the  
//  Outer loop of the function is m times, because (j = 0; j < m; ++j).
//  Therefore, the T(n) = O(n) * O(m) = O(n*m)
bool consec_sum(const int a[], int n, const int b[], int m);


// even_first(a, len) puts all the even numbers before all of the odd numbers
//   in the array a
// effects: modifies a
// time:   O(n^2)
// pretend the worst case happen, all the elements in a[] are even, the inner
//  loop of the even_first(a, len) is O(n-i), which is O(n), because 
//  (j = i; j > 0; --j), the outer loop  of the function is n times, because 
//   (i = 0; i < len; ++i). therefore, T(n) = n*O(n) = O(n^2)
void even_first(int a[], int len);


