#include <stdbool.h>

// SEASHELL_READONLY

// A module for a wordlist ADT

// A word only contains lowercase letters ('a'...'z')
// an empty string ("") is also considered a word

// requirements: ALL string and wordlist parameters are valid (non-NULL)
//               string parameters are words

struct wordlist;

// wordlist_create() creates a new empty wordlist
// effects: allocates memory (must call wordlist_destroy)
struct wordlist *wordlist_create(void);

// wordlist_add(s, wl) adds the word s to wordlist wl
// effects: modifies wl
// time:    O(n), n is the length of s
void wordlist_add(const char *s, struct wordlist *wl);

// wordlist_remove(s, wl) removes the word s from wordlist wl (if it exists)
// effects: may modify wl
// time:    O(n), n is the length of s
void wordlist_remove(const char *s, struct wordlist *wl);

// wordlist_lookup(s, wl) determines if wl contains the word s
// time: O(n), n is the length of s
bool wordlist_lookup(const char *s, const struct wordlist *wl);

// wordlist_destroy(wl) frees all memory for wl
// effects: wl is no longer valid
// time:    O(n), n is the number of characters in all of the words in wl
void wordlist_destroy(struct wordlist *wl);

// wordlist_print(wl) prints each word in wl in alphabetical order,
//   with each word on a newline
// effects: displays output (if wl is not empty)
// time:    O(n^2), n is the number of characters in all of the words in wl
void wordlist_print(const struct wordlist *wl);

// wordlist_count(wl) determines how many words are in wl
// time: O(1)
int wordlist_count(const struct wordlist *wl);


// this is not normally included, but necessary for seashell
#include "trie.h"

