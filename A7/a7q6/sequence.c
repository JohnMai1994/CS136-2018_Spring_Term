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

#include "sequence.h"
#include "cs136-trace.h"
#include <stdio.h>
#include <assert.h>

const int MAXLEN = 1000;

void sequence_init(struct sequence *seq) {
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  seq->len = 0;
  for (int i = 0; i <MAXLEN; ++i) {
     seq->data[i] = 0; 
  }
}

int sequence_length(const struct sequence *seq) {
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);  
  return seq->len;
}

int sequence_item_at(const struct sequence *seq, int pos){
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  assert(0<= pos <= seq->len);
  return seq->data[pos];
}

void sequence_insert_at(struct sequence *seq, int pos, int val){
   assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  assert(0<= pos <= seq->len);
  for (int i = seq->len; pos < i; --i) {
    seq->data[i] = seq->data[i-1]; 
  } 
  seq->len = (seq->len + 1);
  seq->data[pos] = val;
}

int sequence_remove_at(struct sequence *seq, int pos){
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  assert(0<= pos <= seq->len);
  int tmp = seq->data[pos];
  for (int i = pos; pos < i; ++i) {
     seq->data[i] = seq->data[i+1]; 
  }
  seq->len = (seq->len -1);
  return tmp;
}

void sequence_print(const struct sequence *seq){
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  int length = seq->len;
  printf("[");
  if (length==0) {
    printf("empty");
  }
 
  for (int i = 0; i < length ; ++i) {
    if (i == 0) {
      printf("%d", seq->data[i]); 
    }else {
      printf(", %d", seq->data[i]);
    }
  }
  printf("]\n");
}

void sequence_read(struct sequence *seq) {
  assert(seq);
  assert(seq->data);
  assert(seq->len >= 0);
  int i = 0;
  while (1) {
     int digit; 
     int stop = scanf("%d", &digit);  
     if (stop != 1) {
       break; 
     }
     seq->data[i] = digit;
     ++i;
   }
  seq->len = i;
}














