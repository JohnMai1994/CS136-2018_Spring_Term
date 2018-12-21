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

#include "destack.h"
#include "stack.h"
#include "cs136-trace.h"
#include <stdlib.h>
#include <assert.h>

// DO NOT MODIFY THIS STRUCTURE
struct stack {
  struct destack *des;
};


struct stack *stack_create(void) {
  struct stack *sta = malloc(sizeof(struct stack));
  sta->des = destack_create();
  return sta;
}


bool stack_is_empty(const struct stack *s) {
  assert(s);
  return destack_is_empty(s->des); 
}


int stack_top(const struct stack *s) {
  assert(s);
  assert(!destack_is_empty(s->des));
  return destack_top(s->des);
}


int stack_pop(struct stack *s) {
  assert(s);
  assert(!destack_is_empty(s->des));
  return destack_pop_top(s->des);
}


void stack_push(int item, struct stack *s) {
  assert(s);
  destack_push_top(item, s->des);
}


void stack_destroy(struct stack *s) {
  assert(s);
  destack_destroy(s->des);
  free(s);
}


// DO NOT MODIFY THIS FUNCTION
void stack_print(const struct stack *s) {
  assert(s);
  destack_print(s->des);
}