#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pool.h"

/*
 This is simple I/O test client for pool.h that
 uses a very specific input format.

 Failure to follow format might lead to undefined behaviour.
 
 LET is a lowercase letter from a..z to identify each allocation

 create INT: create the pool of size INT
 destroy: destroy the current pool
 alloc LET INT: allocate memory to LET of size INT
 free LET: free memory associated with LET
 realloc LET INT: reallocate memory associated with LET to size INT
 active: print active
 available: print available
 exit: quit
*/


// get_let() reads in a lowercase letter from input and returns
//   it as an index from 0...25
// requires: can read a character, must be between 'a'..'z'
// effects: reads input
int get_let(void) {
  char c = 0;
  assert(scanf(" %c", &c) == 1);
  assert('a' <= c && c <= 'z');
  return c - 'a';
}


int main(void) {
  struct pool *p = NULL;
  char *letters[26] = {0};
  char command[11] = {0};
  int size = 0;
  int let = 0;
  while (scanf("%s", command) == 1 && strcmp(command, "exit")) {
    if (!strcmp(command, "create")) {
      assert (scanf("%d", &size) == 1);
      if (p) {
        printf("create: fail (already created)\n");
      } else {
        p = pool_create(size);
      }
    } else if (!strcmp(command, "destroy")) {
      if (pool_destroy(p)) {
        p = NULL;
      } else {
        printf("destroy: fail (did not free all allocations)\n");
      }
    } else if (!strcmp(command, "alloc")) {
      let = get_let();      
      assert (scanf("%d", &size) == 1);
      if (letters[let]) {
        printf("alloc %c %d: leak (already allocated)\n", 'a' + let, size);
      } else {
        char *ptr = pool_alloc(p, size);
        if (ptr) {
          letters[let] = ptr;
        } else {
          printf("alloc %c %d: fail\n", 'a' + let, size);
        }
      }
    } else if (!strcmp(command, "free")) {
      let = get_let();
      if (pool_free(p, letters[let])) {
        letters[let] = NULL;
      } else {
        printf("free %c: fail\n", 'a' + let);
      }
    } else if (!strcmp(command, "realloc")) {
      let = get_let();      
      assert (scanf("%d", &size) == 1);
      char *ptr = pool_realloc(p, letters[let], size);
      if (ptr) {
        letters[let] = ptr;
      } else {
        printf("realloc %c %d: fail\n", 'a' + let, size);
      } 
    } else if (!strcmp(command, "active")) {
      pool_print_active(p);
    } else if (!strcmp(command, "available")) {
      pool_print_available(p);
    } else {
      printf("Invalid command (%s).\n",command);
      break;
    }
  }
  if (p) {
    if (pool_destroy(p)) {
      printf("ERROR: did not destroy pool\n");
    } else {
      printf("ERROR: did not free all allocations\n");
    }
  }
}
