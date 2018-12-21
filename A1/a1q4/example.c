#include "cs136.h"

// Examples of printing numeric sequences

// Note the subtle differences between 
// print_descending and print_ascending_core:
// They both recursively "count down" from n...1,
// but the order of the recursion and the printf are switched:
//    printf()                      recurse()
//    recurse()         VS.         printf()

// Once you understand these, you can review print_ascending_2
// and see how a "count up" pattern can be used

// Also, note the different choices of when to print the space
// between the numbers.


// print_descending(n) prints the numbers n...1 formatted as:
//   "n n-1 ... 3 2 1.\n"
// requires: n >= 1
// effects:  produces output

void print_descending(int n) {
  assert(n >= 1);
  if (n == 1) {
    printf("1.\n");
  } else {
    printf("%d ", n);
    print_descending(n - 1);
  }
}


// print_ascending_core(n) prints the numbers 1...n formatted as:
//   "1 2 3 ... n-1 n"
// requires: n >= 1
// effects:  produces output

void print_ascending_core(int n) {
  assert(n >= 1);
  if (n == 1) {
    printf("1");
  } else {
    print_ascending_core(n-1);
    printf(" %d", n);
  }
}


// print_ascending(n) is a wrapper for print_acending_core
//   that just adds the ".\n" so the full output becomes:
//   "1 2 3 ... n-1 n.\n"
// requires: n >= 1
// effects:  produces output

void print_ascending(int n) {
  assert(n >= 1);
  print_ascending_core(n);
  printf(".\n");
}


// print_ascending_countup(int i, int n) prints the sequence 
//   "i i+1 ... n-1 n.\n"
// requires: 1 <= i <= n
// effects:  produces output

void print_ascending_countup(int i, int n) {
  assert(1 <= i);
  assert(i <= n);
  if (i < n) {
    printf("%d ", i);
    print_ascending_countup(i + 1, n);
  } else {
    printf("%d.\n", i);
  }
}


// print_ascending_2(n) behaves the same as print_ascending(n)
//   except that it uses a different "count up" helper
// requires: n >= 1
// effects:  produces output

void print_acending_2(int n) {
  assert(n >= 1);
  print_ascending_countup(1, n);
}


int main(void) {
  print_descending(10);
  print_ascending(10);
  print_acending_2(10);
}
