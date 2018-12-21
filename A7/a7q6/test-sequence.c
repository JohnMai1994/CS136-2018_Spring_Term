#include <assert.h>
#include "sequence.h"
#include "cs136-trace.h"

int main(void) {
  struct sequence my_seq = {6, {4, 8, 15, 16, 23, 42}};
  struct sequence *seq = &my_seq;
  sequence_print(seq);
  sequence_init(seq);
  sequence_print(seq);
  sequence_read(seq);
  assert(sequence_length(seq) == 3);
  sequence_insert_at(seq, 0, 0);
  assert(sequence_item_at(seq, 0) == 0);
  sequence_remove_at(seq, 3);
  assert(sequence_length(seq) == 3);
  sequence_print(seq);
}
