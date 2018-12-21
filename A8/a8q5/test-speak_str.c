#include <stdio.h>
#include <stdlib.h>
#include "phonetic.h"
#include "speak.h"
#include "slurp.h"

// a simple test client for speak_str

int main(void) {
  char msg[10001];
  slurp(msg, 10000);
  char s[201];
  speak_str(msg, phonetic, s, 200);
  printf("%s\n", s);
}
