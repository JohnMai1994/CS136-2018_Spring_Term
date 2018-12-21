#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include "cs136-trace.h"

// a simple assertion-based client for the trie module

// you may want to consider making your own I/O based client

int main(void) {
  struct trie *t = trie_create();
  assert(t);
  
  assert(t->root == NULL);
  assert(trie_count(t) == 0);
  
  trie_add("ac", t);
  assert(trie_lookup("ac", t));  
  assert(trie_count(t) == 1);
  
  assert(t->root->children[0]);
  assert(t->root->children[0]->children[2]->word_end);
  trie_print(t); // should just print out "a\n"
  
  char **aos = trie_to_aos(t);
  assert(aos);
  assert(!strcmp("ac", aos[0]));
  free(aos[0]);
  free(aos);
  assert(!trie_lookup("b", t));
  trie_add("b", t);
  
  assert(t->root->children[1]);
  assert(t->root->children[1]->word_end);
  
  assert(trie_lookup("b", t));
  assert(trie_count(t) == 2);
  trie_remove("b", t);

  assert(t->root->children[1] == NULL);
  assert(!trie_lookup("b", t));
  assert(trie_count(t) == 1);
  trie_destroy(t);  
}
