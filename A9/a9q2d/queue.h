#include <stdbool.h>

// Queue: provides a Queue ADT for ints
// NOTE: ALL queue parameters must be valid queues
// n always stands for the number of items in the queue

struct queue;

// queue_create() creates a new empty queue
// effects: allocates memory (client must call queue_destroy)
// time: O(1)
struct queue *queue_create(void);

// queue_is_empty(q) determines if the queue q is empty
// time: O(1)
bool queue_is_empty(const struct queue *q);

// queue_front(q) returns the front item in the queue q
// requires: q is not empty
// time: O(1)
int queue_front(const struct queue *q);

// queue_remove_front(q) returns and removes the front item from the queue q
// requires: q is not empty
// effects: modifies q
// time: O(1)
int queue_remove_front(struct queue *q);

// queue_add_back(item, q) adds item to the back of the queue q
// effects: modifies q
// time: O(1)
void queue_add_back(int item, struct queue *q);

// queue_destroy(q) frees all memory for the queue q
// effects: q is no longer valid
// time: O(1)
void queue_destroy(struct queue *q);

// queue_print(s) prints the contents of the queue q
// effects: prints to output
// time: O(n)
void queue_print(const struct queue *q);
