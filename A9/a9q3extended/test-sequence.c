#include <stdio.h>
#include <assert.h>
#include "sequence.h"
#include "cs136-trace.h"

int main(void) {
  struct sequence *seq = sequence_create();
  sequence_print(seq);
  assert(sequence_length(seq) == 0);
  sequence_insert_at(seq, 0, 27);
  sequence_print(seq);
  assert(sequence_item_at(seq, 0) == 27);
  assert(sequence_length(seq) == 1);
  sequence_destroy(seq);
}
