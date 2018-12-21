#include "cs136-trace.h"
#include "queue.h"
#include <assert.h>

// a simple test client

int main(void) {
  struct queue *q = queue_create();
  queue_add_back(27, q);
  queue_print(q);
  assert(queue_front(q) == 27);
  assert(queue_remove_front(q) == 27);
  assert(queue_is_empty(q));
  queue_destroy(q);
}
