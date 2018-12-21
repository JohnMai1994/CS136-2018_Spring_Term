#include <stdbool.h>

// A Double Ended Stack for ints
// NOTE: ALL double ended stack parameters must be valid
// n always stands for the number of items in the double ended stack

struct destack;

// destack_create() creates a new empty double ended stack
// effects: allocates memory (client must call destack_destroy)
// time: O(1)
struct destack *destack_create(void);

// destack_is_empty(s) determines if the double ended stack s is empty
// time: O(1)
bool destack_is_empty(const struct destack *s);

// destack_top(s) returns the top item in the double ended stack s
// requires: s is not empty
// time: O(1)
int destack_top(const struct destack *s);

// destack_bot(s) returns the bottom item in the double ended stack s
// requires: s is not empty
// time: O(1)
int destack_bot(const struct destack *s);

// destack_pop_top(s) returns and removes the top item from the double ended stack s
// requires: s is not empty
// effects: modifies s
// time: O(1)
int destack_pop_top(struct destack *s);

// destack_pop_bot(s) returns and removes the bottom item from the double ended stack s
// requires: s is not empty
// effects: modifies s
// time: O(1)
int destack_pop_bot(struct destack *s);

// destack_push_top(item, s) adds item to the top of the double ended stack s
// effects: modifies s
// time: O(1)
void destack_push_top(int item, struct destack *s);

// destack_push_bot(item, s) adds item to the bottom of the double ended stack s
// effects: modifies s
// time: O(1)
void destack_push_bot(int item, struct destack *s);

// destack_destroy(s) frees all memory for the double ended stack s
// requires: s must be from a previous malloc
// effects: s is no longer valid
// time: O(1)
void destack_destroy(struct destack *s);

// destack_print(s) prints the contents of the double ended stack s
// effects: prints to output
// time: O(n)
void destack_print(const struct destack *s);
