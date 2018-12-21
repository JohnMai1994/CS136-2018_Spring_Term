#include <stdbool.h>

// SEASHELL_READONLY

// This is a module that provides a trie data structure that stores words

// A word only contains lowercase letters ('a'...'z')
// an empty string ("") is also considered a word

// requirements: ALL string and trie parameters are valid (non-NULL)
//               string parameters are words

struct trienode {
  bool word_end;
  struct trienode *children[26];
};

struct trie {
  struct trienode *root;
};


// trie_create() creates a new empty trie
// effects: allocates memory (must call trie_destroy)
struct trie *trie_create(void);

// trie_add(s, t) adds the word s to trie t
// effects: modifies t
// time:    O(n), n is the length of s
void trie_add(const char *s, struct trie *t);

// trie_remove(s, t) removes the word s from trie t (if it exists)
//   and removes any trienodes that are no longer needed
// effects: may modify t
// time:    O(n), n is the length of s
void trie_remove(const char *s, struct trie *t);

// trie_lookup(s, t) determines if t contains the word s
// time: O(n), n is the length of s
bool trie_lookup(const char *s, const struct trie *t);

// trie_destroy(t) frees all memory for t
// effects: t is no longer valid
// time:    O(n), n is the number of characters in all of the words in t
void trie_destroy(struct trie *t);

// trie_print(t) prints each word in trie t in alphabetical order,
//   with each word on a newline
// effects: displays output (if t is not empty)
// time:    O(n^2), n is the number of characters in all of the words in t
void trie_print(const struct trie *t);

// trie_to_aos(t) generates a new array containing all of the words
//   in trie t in alphabetical order, each word is a new string
// notes:    returns NULL if t is empty
//           use trie_count(t) to determine the length of the array
// effects:  allocates memory (caller must free all strings and the array)
// time:     O(n^2), n is the number of characters in all of the words in t
char **trie_to_aos(const struct trie *t);

// trie_count(t) determines how many words are in t
// time: O(n), n is the number of characters in all of the words in t
int trie_count(const struct trie *t);
