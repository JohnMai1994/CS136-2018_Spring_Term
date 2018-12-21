#include <stdbool.h>
#include <assert.h>
#include "rotten.h"

// a simple test client

int main(void) {
  char *positive[] = { "like", "love", "awesome", "wicked", "fun", "great" };
  char *negative[] = { "hate", "despise", "terrible", "awful", "waste" };
  char *review[] = { "great", "movie", "terrible", "acting", "wicked", 
                    "effects" };
  
  assert(is_fresh(review, 6, positive, 6, negative, 5));
}