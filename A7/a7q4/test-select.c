#include <assert.h>
#include "select.h"

// a simple test program for select
int select_3_helper(int a[],int low, int high);
int a[] = {8, 6, 7, 5, 3, 0, 9, 4, 2, 1};
int b[] = {8, 6, 7, 5, 3, 0, 9, 4, 2, 1};
int c[] = {8, 6, 7, 5, 3, 0, 9, 4, 2, 1};

int main(void) {
  assert(0 == select_1(a, 10, 0));
  assert(0 == select_2(b, 10, 0));
  assert(8 == select_3(c, 10,  8));
}