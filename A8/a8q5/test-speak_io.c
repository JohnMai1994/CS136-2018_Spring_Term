#include <stdio.h>
#include <stdlib.h>
#include "phonetic.h"
#include "speak.h"
#include "slurp.h"

// a simple test client for speak_io

int main(void) {
  char msg[10001];
  slurp(msg, 10000);
  speak_io(msg, phonetic);
}
