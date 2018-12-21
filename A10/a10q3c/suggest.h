#include "wordlist.h"

// SEASHELL_READONLY

// suggest(word, is_word) returns a new wordlist containing
//   correctly spelled words (according to is_word) that have
//   an edit distance of one from word (see assignment)
//   or returns NULL if there are no suggested words
// note:     does not suggest "" or word itself
// requires: word is a valid non-empty string in lowercase
// effects:  may create a new wordlist (client calls wordlist_destroy)

struct wordlist *suggest(const char *word,
                         bool (*is_word)(const char *));

