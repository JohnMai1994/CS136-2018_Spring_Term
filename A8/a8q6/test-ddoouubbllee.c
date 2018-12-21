#include <stdio.h>
#include <stdlib.h>
#include "ddoouubbllee.h"

// a simple i/o test client for ddoouubbllee

int main(void) {
  char s[100];
  while (scanf("%s", s) == 1) {
    char *d = ddoouubbllee(s);
    printf("%s\n", d);
    free(d);
  }
}
