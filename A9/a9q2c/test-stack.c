#include "cs136-trace.h"
#include "stack.h"
#include <assert.h>

// a simple test client

int main(void) {
  struct stack *s = stack_create();
  stack_push(27, s);
  stack_push(55,s);
  stack_print(s);
  assert(stack_top(s) == 55);
  assert(stack_pop(s) == 55);
  stack_print(s);
  assert(!stack_is_empty(s));
  stack_destroy(s);
}
