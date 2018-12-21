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

#include "desll.h"
#include "cs136-trace.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// DO NOT MODIFY THIS STRUCTURE
struct dllnode {
  int item;
  struct dllnode *prev;
  struct dllnode *next;
};

// DO NOT MODIFY THIS STRUCTURE
struct destack {
  struct dllnode *top;
  struct dllnode *bot;
};


struct destack *destack_create(void) {
  struct destack *des = malloc(sizeof(struct destack));
  des->top = NULL;
  des->bot = NULL;
  return des;
}


bool destack_is_empty(const struct destack *s) {
  assert(s);
  if ((s->top == NULL) && (s->bot == NULL)) return true;
  return false;
}


int destack_top(const struct destack *s) {
  assert(s);
  assert(s->top);
  int value = s->top->item;
  return value;
}


int destack_bot(const struct destack *s) {
  assert(s);
  assert(s->bot);
  int value = s->bot->item;
  return value;
}

struct dllnode *new_node(int i, struct dllnode *pprev, struct dllnode *pnext) {
  struct dllnode *node = malloc(sizeof (struct dllnode)); 
  node->item = i;
  node->prev = pprev;
  node->next = pnext;
  return node;
}



int destack_pop_top(struct destack *s) {
  assert(s);
  assert(s->top);
  int top_value = s->top->item;
  struct dllnode *del = s->top;
  s->top->prev->next = NULL;
  s->top = s->top->prev;
  free(del);
  return top_value;
}


int destack_pop_bot(struct destack *s) {
  assert(s);
  assert(s->bot);
  int bot_value = s->bot->item;
  struct dllnode *del = s->bot;
  s->bot->next->prev = NULL;
  s->bot= s->bot->next;
  free(del);
  return bot_value;
}


void destack_push_top(int item, struct destack *s) {
  assert(s);
  struct dllnode *node = new_node(item, s->top, NULL);
  if ((s->top == NULL) &&(s->bot == NULL)) {
    s->top = node;
    s->bot = node;
  } else {
    s->top->next = node;
  }
  s->top = node;
  
}


void destack_push_bot(int item, struct destack *s){
  assert(s);
  struct dllnode *node = new_node(item, NULL, s->bot);
  if ((s->top == NULL) &&(s->bot == NULL)) {
    s->top = node;
    s->bot = node;
  } else{
    s->bot->prev = node;
  }
  s->bot = node;
}


void destack_remove_front(struct destack *s){
  assert(s);
  struct dllnode *old_front = s->top;
  s->top = s->top->next;
  free(old_front);
  if (s->top == NULL){
    s->bot = NULL;
  }
}

void destack_destroy(struct destack *s) {
  assert(s);
  while (!destack_is_empty(s)) {
    destack_remove_front(s); 
  }
  free(s);
}

// DO NOT MODIFY THIS FUNCTION
void destack_print(const struct destack *s) {
  assert(s);
  struct dllnode *temp = s->bot;

  printf("Destack:\n");
  printf("Bot -> ");
  while (temp) {
    printf("%d -> ", temp->item);
    temp = temp->next;
    
  }
  printf("NULL\n");

  temp = s->top;
  printf("Top -> ");
  while (temp) {
    printf("%d -> ", temp->item);
    temp = temp->prev;
  }
  printf("NULL\n");
}
