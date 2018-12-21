#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "cs136-trace.h"

// assertion-based demo using constant string literals

// the free function we provide does nothing because
// there is no need to free string literals


// my_strcmp(a, b) is the same as strcmp, except it accepts voids
// requires: a, b are both valid (non-NULL) char *'s
int my_strcmp(void *a, void *b) {
  const char *string_a = a;
  const char *string_b = b;
  return strcmp(string_a, string_b);
}

// do_nothing(p) does absoluetly nothing
void do_nothing(void *p) {
}

// my_print(key, val) prints the key and val for debugging
// requires: a, b are both valid (non-NULL) char *'s
// effects:  displays output
void my_print(void *key, void *val) {
  const char *string_key = key;
  const char *string_val = val;
  printf("key: %s, value: %s\n", string_key, string_val);
}

int main(void) {
  
  
  struct dictionary *d = dict_create(my_strcmp, 
                                     do_nothing,
                                     do_nothing,
                                     my_print);
  
  assert(d);
  
  
  dict_insert("3141593", "Archie", d);
  dict_insert("1234567", "Bobby", d);
  
  dict_insert("1234567", "Sally", d); 
  dict_insert("8675309", "Jenny", d);

  
  assert(dict_lookup("BOGUS_KEY", d) == NULL);
  assert(!my_strcmp(dict_lookup("8675309", d), "Jenny"));

  printf("===== INORDER:\n");
  dict_print(INORDER, d);
  printf("===== PREORDER:\n");
  dict_print(PREORDER, d);
  printf("===== POSTORDER:\n");
  dict_print(POSTORDER, d);
/*  
expected output: visually inspect
   (the I/O TESTs are for test-double-dict.c, not this file)

===== INORDER:
key: 1234567, value: Sally
key: 3141593, value: Archie
key: 8675309, value: Jenny
===== PREORDER:
key: 3141593, value: Archie
key: 1234567, value: Sally
key: 8675309, value: Jenny
===== POSTORDER:
key: 1234567, value: Sally
key: 8675309, value: Jenny
key: 3141593, value: Archie

*/
  
  assert(dict_count(d) == 3);  
  
  assert(!my_strcmp("1234567", dict_select(0, d)));
  assert(!my_strcmp("3141593", dict_select(1, d)));
  assert(!my_strcmp("8675309", dict_select(2, d)));
  
  
  dict_destroy(d);
  
}
