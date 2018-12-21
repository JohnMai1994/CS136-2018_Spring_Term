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

#include "desarray.h"
#include "cs136-trace.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// DO NOT MODIFY THIS STRUCTURE
struct destack {
  int top;
  int bot;
  int len;
  int maxlen;
  int *stack;
};


struct destack *destack_create(void) {
  struct destack *s = malloc(sizeof(struct destack));
  s->top = -1;
  s->bot = -2;
  s->len = 0;
  s->maxlen = 1;
  s->stack = malloc(s->maxlen * sizeof(int));
  return s;
}


bool destack_is_empty(const struct destack *s) {
  assert(s);
  if (s->len == 0)  {
    return true;
  } else {
    return false;
  }

}


int destack_top(const struct destack *s) {
  assert(s);
  assert(s->len > 0);
  return s->stack[s->top];
}


int destack_bot(const struct destack *s) {
  assert(s);
  assert(s->len > 0);
  return s->stack[s->bot];
}


int destack_pop_top(struct destack *s) {
  assert(s);
  assert(s->len >0);
  if (5 * s->len < s->maxlen) {
    s->maxlen = 3* s->len;
    int *new_stack = malloc(s->maxlen * sizeof(int));
    int new_position = s->len;
    for (int i = s->bot; i <= s->top; ++i){ 
      new_stack[new_position++] = s->stack[i];
    }
    s->top = 2*s->len-1;
    s->bot = s->len;
    free(s->stack);
    s->stack = new_stack;
  }
  int top_value;
  if (s->top == s->bot) {
    top_value = s->stack[s->top];
    s->top = -1;
    s->bot = -2;
    s->len--;
    s->maxlen = 1;
  } else{
    top_value = s->stack[s->top];
    s->top = s->top -1;
    s->len = s->len -1;
  }
  return top_value;
}


int destack_pop_bot(struct destack *s) {
  assert(s);
  assert(s->len >0);
  if (5 * s->len < s->maxlen) {
    s->maxlen = 3* s->len;
    int *new_stack = malloc(s->maxlen * sizeof(int));
    int new_position = s->len;
    for (int i = s->bot; i <= s->top; ++i){ 
      new_stack[new_position++] = s->stack[i];
    }
    s->top = 2*s->len-1;
    s->bot = s->len;
    free(s->stack);
    s->stack = new_stack;
  }
  int bot_value;
  if (s->top == s->bot) {
    bot_value = s->stack[s->bot];
    s->top = -1;
    s->bot = -2;
    s->len--;
    s->maxlen = 1;
  } else{
    bot_value = s->stack[s->bot];
    ++s->bot;
    --s->len;
  }
  return bot_value;
}


void destack_push_top(int item, struct destack *s) {
  assert(s);
  if (s->top == s->maxlen - 1){
    s->maxlen = 3*s->len;
    int *new_stack = malloc(s->maxlen * sizeof(int));
    int new_position = s->len;
    for (int i = s->bot; i <= s->top; ++i){ 
      new_stack[new_position++] = s->stack[i];
    }
    s->top = 2*s->len-1;
    s->bot = s->len;
    free(s->stack);
    s->stack = new_stack;
  }

  if (s->maxlen == 1){
    s->top = 0;
    s->bot = 0;
    s->stack[s->top] = item;
    ++s->len;
  } else{
    s->stack[++s->top] = item;
    s->len += 1;
  }

}


void destack_push_bot(int item, struct destack *s) {
  assert(s);
  if (s->bot == 0) {
    s->maxlen = 3*s->len;
    int* new_stack = malloc(s->maxlen * sizeof(int));
    int new_position = s->len;
    for (int i = s->bot; i <= s->top; ++i){
      new_stack[new_position++] = s->stack[i];       
    }
    s->top = 2*s->len -1;
    s->bot = s->len;
    free(s->stack);
    s->stack = new_stack;
  }

  if (s->maxlen == 1){
    s->top = 0;
    s->bot = 0;
    s->stack[s->bot] = item;
    ++s->len;
  } else{
    s->stack[--s->bot] = item;
    s->len ++;
  }
}


void destack_destroy(struct destack *s) {
  assert(s);
  free(s->stack);
  free(s);
}


// DO NOT MODIFY THIS FUNCTION
void destack_print(const struct destack *s) {
  assert(s);
  printf("Destack: [%d...%d], %d of %d\n", s->bot, s->top, s->len, s->maxlen);
  if (!s->len) {
    printf("[empty]\n");
    return;
  }
  for (int i = s->top; i >= s->bot; --i) {
    printf("%d\n", s->stack[i]);
  }
}
