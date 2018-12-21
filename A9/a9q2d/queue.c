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
#include "queue.h"
#include "cs136-trace.h"
#include <stdlib.h>
#include <assert.h>

// DO NOT MODIFY THIS STRUCTURE
struct queue {
  struct destack *des;
};


struct queue *queue_create(void) {
  struct queue *que = malloc(sizeof(struct queue));
  que->des = destack_create();
  return que;
}


bool queue_is_empty(const struct queue *q) {
  assert(q);
  return destack_is_empty(q->des);
}


int queue_front(const struct queue *q) {
  assert(q);
  assert(q->des);
  return destack_bot(q->des);
}


int queue_remove_front(struct queue *q) {
  assert(q);
  assert(q->des);
  return destack_pop_top(q->des);
}


void queue_add_back(int item, struct queue *q) {
  assert(q);
  return destack_push_bot(item, q->des);
}


void queue_destroy(struct queue *q) {
  assert(q);
  destack_destroy(q->des);
  free(q);
}


// DO NOT MODIFY THIS FUNCTION
void queue_print(const struct queue *q) {
  assert(q);
  destack_print(q->des);
}