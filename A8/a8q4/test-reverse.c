#include <assert.h>
#include <string.h>
#include "cs136-trace.h"
#include "reverse.h"
#include <stdio.h>

// a simple test client



int main(void){
  char abc[] = "abc";
  reverse(abc);
  assert(!strcmp(abc, "cba"));
  char batman[] = "I am Batman";
  reverse_words(batman);
  assert(!strcmp(batman, "Batman am I"));

}
