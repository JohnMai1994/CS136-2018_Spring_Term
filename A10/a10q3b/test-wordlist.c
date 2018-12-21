#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "wordlist.h"

// a simple test client for wordlist

// PHASE ONE:   reads words from input until "STOP" is read
//              adding each word
// PHASE TWO:   reads words from input until "STOP" is read
//              looking up each word
// PHASE THREE: reads words from input intil EOF
//              removing each word
// PHASE FOUR:  prints the number of words remaining
//              prints the remaining words

int main(void) {
  char word[21];
  struct wordlist *wl = wordlist_create();
  assert(wl);
  while (scanf("%s", word) == 1 && strcmp(word, "STOP")) {
    wordlist_add(word, wl);
  }
  while (scanf("%s", word) == 1 && strcmp(word, "STOP")) {
    if (wordlist_lookup(word, wl)) {
      printf("%s: true\n", word);
    } else {
      printf("%s: false\n", word);
    }
  }
  while (scanf("%s", word) == 1) {
    wordlist_remove(word, wl);
  }  
  printf("%d\n", wordlist_count(wl));
  wordlist_print(wl);
  wordlist_destroy(wl);
}
