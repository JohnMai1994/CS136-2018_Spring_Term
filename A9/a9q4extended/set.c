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

#include "mergesort.h"
#include "set.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "cs136-trace.h"


struct set{
  int len;
  int maxlen;
  int *stack;
};


struct set *set_create(void){
  struct set *s = malloc(sizeof(struct set));
  s->len = 0;
  s->maxlen = 1;
  s->stack = malloc(s->maxlen * sizeof(int));
  return s;
}


void set_destroy(struct set *s){
  assert(s);
  free(s->stack);
  free(s);
}


int set_size(const struct set *s){
  assert(s);
  return s->len; 
}



bool set_member(const struct set *s, int i){
  assert(s);
  if (s->len == 0) return false;
  if (s->len == 1) return (s->stack[0] == i);
  int low = 0;
  int high = s->len-1;
  while(low <= high) {
    int mid = (low +high)/2;
    if (s->stack[mid] == i) return true;
    if (s->stack[mid] < i) {
      low = mid +1;
    } else {
      high = mid -1; 
    }
  }
  return false;
}


void set_add(struct set *s, int i){
  assert(s);
  if (set_member(s, i)) return;
  if (s->len == s->maxlen) {
    s->maxlen = 2*s->maxlen;
    s->stack = realloc(s->stack, s->maxlen * sizeof(int));
  }

  if (s->len == 0 ) {
    s->stack[s->len] = i; 
    s->len++;
  } else{
    int temp = i;
    int replace = i;
    for(int k = 0; k <= s->len; ++k){
      if(s->len == k) {
        s->stack[k] = temp;
      } else if(s->stack[k] < temp) {
        continue;
      } else if(s->stack[k] == temp) {
        s->len--;
        break;
      } else {
        replace = s->stack[k];
        s->stack[k] = temp;
        temp = replace;
      }
    }
    s->len++;
  }

}


void set_remove(struct set *s, int i){
  assert(s);
  if (s->len == 0) return;
  if (set_member(s, i)){
    for (int k = 0; k < s->len; ++k){
      if (s->stack[k] == i){
        s->stack[k] = -1000;
      }
    }
    int *new_stack = malloc(s->maxlen * sizeof(int));
    int begin = 0;
    for(int j= 0; j< s->len; ++j){
      if (s->stack[j] == -1000) continue;
      new_stack[begin++] = s->stack[j];
    }
    free(s->stack);
    s->stack = new_stack;
    --s->len;
  }
}


struct set *set_union(const struct set *s1, const struct set *s2){
  assert(s1);
  assert(s2);
  int po1 = 0;
  int po2 = 0;
  int pos = 0;
  
  int *new_stack = malloc((s1->maxlen + s2->maxlen)*sizeof(int));
  struct set *new_set = set_create();
  new_set->maxlen = s1->maxlen + s2->maxlen;
  while((po1 < s1->len)&&(po2 < s2->len)) {

    if (s1->stack[po1] < s2->stack[po2]) {
      new_stack[pos++] = s1->stack[po1++];
    } else if (s1->stack[po1] == s2->stack[po2]){
      new_stack[pos++] = s1->stack[po1];
      po1++;
      po2++;
    } else {
      new_stack[pos++] = s2->stack[po2++]; 
    }
  }

  while (po1 < s1->len){
    new_stack[pos++] = s1->stack[po1++];
  }

  while (po2 < s2->len) {

    new_stack[pos++] = s2->stack[po2++];
  }
  new_set->len = pos;
  free(new_set->stack);
  new_set->stack = new_stack;
  return new_set;

}


struct set *set_intersect(const struct set *s1, const struct set *s2){
  assert(s1);
  assert(s2);
  int po1 = 0;
  int po2 = 0;
  int pos = 0;
  int *new_stack = malloc((s1->maxlen + s2->maxlen)*sizeof(int));
  struct set *new_set = set_create();
  new_set->maxlen = s1->maxlen + s2->maxlen;
  while((po1< s1->len)&&(po2 < s2->len)){
    if (s1->stack[po1] == s2->stack[po2]) {
      new_stack[pos++] = s1->stack[po1];
      po1++;
      po2++;
    } else if (s1->stack[po1] < s2->stack[po2]) {
      ++po1; 
    } else{
      ++po2; 
    }
  }
  free(new_set->stack);
  new_set->stack = new_stack;
  new_set->len = pos;
  return new_set;
}

struct set *array_to_set(const int a[], int len){
  assert(len>0);
  assert(a);
  struct set *s = set_create();
  s->maxlen = len;
  free(s->stack);
  s->stack = malloc(s->maxlen * sizeof(int));

  int * new_int_array = malloc(len * sizeof(int));
  for (int i = 0; i < len; ++i){
    new_int_array[i] = a[i]; 
  }
  merge_sort(new_int_array,len);
  int pos =0;
  for (int i = 0; i < len; ++i){
    if (i == 0) {
      s->stack[pos++] = new_int_array[i];
    } else if (new_int_array[i] == new_int_array[i-1]) {
      continue; 
    } else {
      s->stack[pos++] = new_int_array[i];
    }
  }
  s->len = pos;
  free(new_int_array);
  return s;
}


int *set_to_array(const struct set *s){
  assert(s);
  int * new_int_array = malloc(s->len * sizeof(int));
  for (int i = 0; i < s->len; ++i){
    new_int_array[i] = s->stack[i]; 
  }
  return new_int_array;
}


void set_print(const struct set *s){
  assert(s);
  printf("[");
  if (s->len == 0){
    printf("empty");
  } else{
    for (int i = 0; i < s->len; ++i){
      printf("%d", s->stack[i]);
      if (i < s->len-1) {
        printf(",");
      }
    }
  }
  printf("]\n");
}