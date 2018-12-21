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
  int length;
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
  sequence->length = 0;
  sequence->data = NULL;
  return sequence;
}


void sequence_destroy(struct sequence *seq) {
  assert(seq);
  struct llnode *temp = seq->data;
  while (temp){
    seq->data = temp->next;
    free(temp);
    temp = seq->data;
  }
  free(seq);
}


int sequence_length(const struct sequence *seq) {
  assert(seq);
  return seq->length;
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
  struct llnode *newnode = malloc(sizeof(struct llnode));
  seq->length += 1;
  newnode ->item = val;
  if (pos == 0){
    newnode->next = seq->data;
    seq->data = newnode;
  } else {
    struct llnode *prev = seq->data;
    while (pos>1) {
      --pos;
      prev = prev->next;
    }
    newnode->next = prev->next;
    prev->next = newnode;
  }
}




int sequence_remove_at(struct sequence *seq, int pos) {
  assert(seq);
  assert(pos>=0);
  assert(pos < sequence_length(seq));
  struct llnode *temp = seq->data;
  struct llnode *prev = seq->data;
  int returnitem;
  if (pos == 0){
    returnitem  = temp-> item;
    seq->data = temp->next;
    free(temp);
    seq->length -= 1;
    return returnitem;
  }
  while (pos != 1){
    prev = prev ->next;
    --pos;
  }
  temp = prev ->next;
  prev->next = temp->next;
  returnitem = temp->item;
  free(temp);
  seq->length -= 1;
  return returnitem;
}


void sequence_print(const struct sequence *seq) {
  struct llnode *node = seq->data;
  if (!node) {
    printf("[empty]\n");
  } else {
    printf("[%d", node->item);
    node = node->next;
    while (node){
      printf(",%d", node->item);
      node = node->next;
    }

    printf("]\n");
  }
}

