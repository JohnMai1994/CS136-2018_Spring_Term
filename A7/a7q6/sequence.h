// An Integer Sequence Module

// NOTE: ALL sequence parameters must be valid

extern const int MAXLEN; // 1000

struct sequence {
  int len;
  int data[1000];
};

// sequence_init(seq) initilizes sequence to be empty
// effects: modifies seq
// time: O(1)
void sequence_init(struct sequence *seq);

// sequence_length(seq) returns the number of items in seq
// time: O(1)
int sequence_length(const struct sequence *seq);

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq)
// time:     O(1)
int sequence_item_at(const struct sequence *seq, int pos);

// sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of items at position >= pos)
// requires: 0 <= pos <= sequence_length(seq) < MAXLEN
// effects:  seq is modified
// time:     O(n)
void sequence_insert_at(struct sequence *seq, int pos, int val);

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of items > pos)
// requires: 0 <= pos < sequence_length(seq)
// effects:  seq is modified
// time:     O(n)
int sequence_remove_at(struct sequence *seq, int pos);

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0, item_1, ..., item_last]\n"
//   or "[empty]\n"
// effects: displays output
// time:    O(n)
void sequence_print(const struct sequence *seq);

// sequence_read(seq) reads in integers from input until EOF or error
//   and replaces the items in seq with the numbers read from input
// effects: reads input
// time:    O(n)
void sequence_read(struct sequence *seq);
