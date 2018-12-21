#include <assert.h>
#include <string.h>
#include "cs136-trace.h"
#include "shrnkstrngs.h"


// a simple test client

int main(void){
  char test[] = "rick and morty";
  remove_whitespace(test);
  assert(!strcmp(test, "rickandmorty"));
  
  char test2[] = "          ";
  remove_whitespace(test2);
  assert(!strcmp(test2, ""));
  
  remove_char(test, 'r');
  assert(!strcmp(test, "ickandmoty"));
  remove_chars(test, "dikmnoy");
  assert(!strcmp(test, "cat"));
}
