#include <assert.h>
#include <stdlib.h>
#include "set.h"
#include <stdio.h>
#include "cs136-trace.h"

// a simple test client

int main(void) {
  int a[] = {3, 2, 1, 1, 2, 3};
  struct set *set_a = array_to_set(a, 6);
  set_print(set_a);
  assert(set_size(set_a) == 3);
  assert(set_member(set_a, 2));
  set_remove(set_a, 2);
  set_print(set_a);
  assert(!set_member(set_a, 2));
  struct set *set_b = set_create();
  set_print(set_b);
  set_add(set_b, 2);
  set_print(set_b);
  struct set *set_c = set_union(set_a, set_b);
  set_print(set_c);
  struct set *set_d = set_intersect(set_b, set_c);
  set_print(set_d);
  int *e = set_to_array(set_d);
  assert(e[0] == 2);
  set_destroy(set_a);
  set_destroy(set_b);
  set_destroy(set_c);
  set_destroy(set_d);
  free(e);
}
