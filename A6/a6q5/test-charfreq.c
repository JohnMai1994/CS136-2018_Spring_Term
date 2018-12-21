#include <stdio.h>
#include "charfreq.h"

// a simple test program for charfreq

int main(void) {
  int freqs[27] = {0};
  charfreq(freqs);
  printf("0: %d\n", freqs[0]);
  for (int i = 1; i <= 26; ++i) {
    printf("%c: %d\n", 'A' + i - 1, freqs[i]);
  }
}
