#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "largest-sum.h"

int main(void) {
  int array[7] = {0, 1, 2, 3, 4, 5, 6};
  assert(largest_sum(array, 7, 3) == 15);
}
