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
#include "trie.h"
#include "wordlist.h"
#include <assert.h>

struct wordlist{
  int count;
  struct trie *trie;
};


struct wordlist *wordlist_create(void) {
  struct wordlist *dictionary = malloc(sizeof(struct wordlist));
  dictionary->trie = trie_create();
  dictionary->count = 0;
  return dictionary;
}


void wordlist_add(const char *s, struct wordlist *wl) {
  assert(wl);
  struct trie *t = wl->trie;
  wl->count += 1;
  trie_add(s, t);
}


void wordlist_remove(const char *s, struct wordlist *wl) {
  assert(wl);
  struct trie *t = wl->trie;
  wl->count -= 1;
  trie_remove(s, t);
}


bool wordlist_lookup(const char *s, const struct wordlist *wl) {
  assert(wl);
  if (wl->trie == NULL) return false;
  struct trie *t = wl->trie;
  if (t->root == NULL) return false;
  return trie_lookup(s, wl->trie);
}


void wordlist_destroy(struct wordlist *wl) {
  assert(wl);
  trie_destroy(wl->trie);
  free(wl);
}


void wordlist_print(const struct wordlist *wl) {
  assert(wl);
  trie_print(wl->trie);
}


int wordlist_count(const struct wordlist *wl) {
  assert(wl);
  return wl->count;
}
