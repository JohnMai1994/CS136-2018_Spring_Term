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

#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "cs136-trace.h"
#include <assert.h>


// DO NOT MODIFY THIS STRUCTURE
struct llnode {
  int item;
  struct llnode *next;
};

// you can modify this structure
struct sequence {
  struct llnode *data;
};

struct llnode *new_node(int i, struct llnode *pnext) {
  struct llnode *node = malloc(sizeof(struct llnode));
  node->item = i;
  node->next = pnext;
  return node;
}


struct sequence *sequence_create(void) {
  struct sequence *sequence = malloc(sizeof(struct sequence));
  sequence->data = NULL;
  return sequence;
}


void sequence_destroy(struct sequence *seq) {
  assert(seq);
  struct llnode *curnode = seq->data;
  struct llnode *nextnode = NULL;
  while (curnode){
    nextnode = curnode -> next;
    free(curnode);
    curnode = nextnode;
  }
  free(seq);
}


int sequence_length(const struct sequence *seq) {
  assert(seq);
  int len = 0;
  struct llnode *node = seq->data;
  while(node) {
    ++len;
    node = node->next;
  }
  return len;
}


int sequence_item_at(const struct sequence *seq, int pos) {
  assert(seq);
  assert(pos>=0);
  assert(pos < sequence_length(seq));
  struct llnode *node = seq->data;
  for(int i = 0; i < pos; i++) {
    node = node-> next;
  }
  return node->item;
}



void sequence_insert_at(struct sequence *seq, int pos, int val) {
  assert(seq);
  assert(pos >= 0);
  assert(pos <= sequence_length(seq));
  if (pos == 0 || seq->data == NULL){
    seq->data = new_node(val, seq->data);
  } else {
    struct llnode *prevnode = seq->data; 
    for (int i = 0; i < pos; ++i){
       prevnode = prevnode->next; 
    }
    prevnode->next = new_node(val, prevnode->next);
  }
}


int sequence_remove_at(struct sequence *seq, int pos) {
  assert(seq);
  assert(pos>=0);
  assert(pos < sequence_length(seq));
  if (pos == 0){
    struct llnode * old_front = seq->data;
    int z = old_front-> item;
    seq->data = seq->data->next;
    free(old_front);
    return z;
  }
  struct llnode *prevnode = seq->data;
  while (pos != 1){
    prevnode = prevnode ->next;
    --pos;
  }
  struct llnode *old_node1 = prevnode ->next;
  int k = old_node1->item;
  prevnode ->next = prevnode ->next-> next;
  free(old_node1);
  return k;
}


void sequence_print(const struct sequence *seq) {
  struct llnode *node = seq->data;
  printf("[");
  if (node == NULL) printf("empty");
  while (node){
    if (node->next == NULL) {
      printf("%d", node->item);
    } else {
    printf("%d,", node->item);
    } 
    node = node->next;
    
  }

  printf("]\n");
}

