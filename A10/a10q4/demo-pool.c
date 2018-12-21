#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pool.h"
#include "cs136-trace.h"

/* 
   This is demo, showing how the pool functions behave similar
   to thier "original" counterparts
*/
 
int main(void) {
  struct pool *p = pool_create(100);
  
  char *string1 = pool_alloc(p, 11);
  strcpy(string1, "string one");
  char *string2 = pool_alloc(p, 11);
  strcpy(string2, "string two");

  
  string1 = pool_realloc(p, string1, 25);
  
  trace_int(strlen(string1));
  strcat(string1, " is now longer");
  
  assert(!strcmp(string1, "string one is now longer"));
  
  strcpy(string2, "uh oh.. an overflow of string two");
  
  assert(!strcmp(string1, "overflow of string two"));
  
  assert(pool_free(p, string1));
  assert(!pool_free(p, string1));
  assert(pool_free(p, string2));
  
  assert(pool_destroy(p));
}
