// a Select Module

// select_1(a, len, k) finds the element of a with index k
//   if a was sorted in ascending (non-decreasing) order
// examples: select(a, len, 0) finds the minimum of a
//           select(a, len, len - 1) finds the maximum of a
// time: O(n^2)
int select_1(const int a[], int len, int k);


// select_2(a, len, k) is the same as select_1,
//   except that it also sorts a
// effects: modifies a
// time:    O(nlogn)
int select_2(int a[], int len, int k);


// select_3(a, len, k) is the same as select_1,
//   except that it may modify a
// effects: modifies a
// time:    O(???) -- see notes in implementation
int select_3(int a[], int len, int k);
