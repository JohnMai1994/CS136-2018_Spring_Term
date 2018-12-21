#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "spellcheck.h"
#include "suggest.h"

// a simple test client for the suggest module

int main(void) {
  char word[21];
  while (scanf("%s", word) == 1) {
    printf("===== %s\n", word);
    struct wordlist *wl = suggest(word, spellcheck);
    if (wl) {
      wordlist_print(wl);
      wordlist_destroy(wl);
    }
  }
}
