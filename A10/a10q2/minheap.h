#include <stdbool.h>

// SEASHELL_READONLY

// A Module for a minheap data structure

struct minheap {
  int len;
  int maxlen;
  int *data;
};

// minheap_create() creates a new empty minheap
// effects: allocates memory (client must call minheap_destroy)
struct minheap *minheap_create(void);

// minheap_is_empty(h) determines if heap h is empty
// time: O(1)
bool minheap_is_empty(const struct minheap *h);

// minheap_insert(i, h) adds i to heap h
// effects: h is modified
// time:    O(logn), n is the size of the heap
void minheap_insert(int i, struct minheap *h);

// minheap_top(h) returns the top of the heap
// requires: h is not empty
// time:     O(1)
int minheap_top(const struct minheap *h);

// minheap_remove(h) removes and returns the top of the heap
// requires: h is not empty
// effects:  h is modified
// time:     O(logn), n is the size of the heap
int minheap_remove(struct minheap *h);

// minheap_destroy(h) frees all memory for h
// effects: h is no longer valid
// time:    O(1)
void minheap_destroy(struct minheap *h);

// heapsort(a, len) sorts a in ascending order
// requires: a is a valid array, len > 0
// effects:  modifies a
// time:     O(nlogn)
void heapsort(int a[], int len);
