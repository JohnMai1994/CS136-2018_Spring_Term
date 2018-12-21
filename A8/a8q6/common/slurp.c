#include <assert.h>
#include <stdio.h>
#include "slurp.h"

void slurp(char *s, int maxlen) {
  assert(s);
  assert(maxlen > 0);
  int i = 0;
  while (i < maxlen && scanf("%c", s + i) == 1) {
    ++i;
  }
  s[i] = '\0';
}
