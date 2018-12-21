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

#include <stdlib.h>
#include "minheap.h"
#include <assert.h>
#include "cs136-trace.h"



struct minheap *minheap_create(void) {
  struct minheap *heap = malloc(sizeof(struct minheap));
  heap->len =0;
  heap->maxlen = 1;
  heap->data = malloc(heap->maxlen * sizeof(int));
  return heap;
}


bool minheap_is_empty(const struct minheap *h) {
  assert(h);
  if (h->len == 0) return true;
  return false;
}


void minheap_insert(int i, struct minheap *h) {
  assert(h);
  while (h->len == h->maxlen) {
    h->maxlen = 2 * h->maxlen +1;
    h->data = realloc(h->data, h->maxlen * sizeof(int)); 
  }
  h->data[h->len] = i;
  int location = h->len;
  int parentnode;
  while (location > 0){
    parentnode = (location -1) /2;

    if (i >= h->data[parentnode]) {
      break;
    }     
    h->data[location] = h->data[parentnode];
    h->data[parentnode] = i;
    location = parentnode;
  } 
  h->len += 1;
}


int minheap_top(const struct minheap *h) {
  assert(h);
  assert(h->len >0);
  return h->data[0];
}

void swap(int *n1, int *n2){
  int temp = *n1;
  *n1 = *n2;
  *n2 = temp;
}



int minheap_remove(struct minheap *h) {
  assert(h);
  int return_value = h->data[0];

  h->data[0] = h->data[h->len-1];
  h->len -= 1;
  int location = 0;
  while (location > h->len){
    int left = location*2 +1;
    int right = location*2 +2;
    if ((h->data[location] <= h->data[left])&&
        (h->data[location] <= h->data[right])) {
      break; 
    } else if (((h->data[left] < h->data[location])&&
                (h->data[left] <= h->data[right])) ||
               //说明right是not exist
               (h->data[left] < h->data[location])){
      swap(&h->data[location], &h->data[left]);
      location = left;
    } else {
      swap(&h->data[location], &h->data[right]);
      location = right;
    }
  }
  return return_value;
}


void minheap_destroy(struct minheap *h) {
  assert(h);
  free(h->data);
  free(h);
}


void heapsort(int a[], int len) {
  assert(a);
  assert(len>=0);
  struct minheap *h = minheap_create();
  for (int i = 0; i < len; ++i){
    minheap_insert(a[i], h);
  }
  for (int i = 0; i < len; ++i){
    a[i] = minheap_remove(h);
  }

  minheap_destroy(h);
}
