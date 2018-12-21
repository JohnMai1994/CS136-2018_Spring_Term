#include <stdbool.h>

// A Pool ADT that provides dynamic, resizable character arrays. 

// SEASHELL_READONLY

struct pool;

// NOTE: All of the following functions REQUIRE:
//       pointers to a pool (e.g., p) are valid (i.e., not NULL)
//       and all sizes (e.g., size) greater than zero

// TIME: n is the number of "active" allocations, which is the number
//       of successful allocs that have not been freed

// SEE ASSIGNMENT TEXT for the behaviour rules of pool_alloc and pool_realloc

// pool_create() creates a new pool of size characters
// effects: allocates memory (caller must call pool_destroy)
// time: O(1)
struct pool *pool_create(int size);

// pool_destroy(p) destroys the pool p if there are no active allocations
//   returns true if successful or false if there are active allocations
// effects:  the memory at p is invalid (freed) if successful
// time: O(1)
bool pool_destroy(struct pool *p);

// pool_alloc(p, size) returns a pointer to an uninitialized char array 
//   of size from within pool p, or NULL if no block of size is available
// effects: modifies p if successful
// time: O(n)
char *pool_alloc(struct pool *p, int size);

// pool_free(p, addr) makes the active allocation at addr available in the pool.
//   returns true if successful (addr corresponds to an active allocation
//   from a previous call to pool_alloc or pool_realloc) or false otherwise
// effects: modifies p if successful
// time: O(n)
bool pool_free(struct pool *p, char *addr);

// pool_realloc(p, addr, size) changes the size of the active allocation at
//   addr and returns the new address for the allocation.
//   returns NULL if addr does not correspond to an active allocation 
//   or the pool can not be resized (in which case the original allocation
//   does not change)
// effects: modifies p if successful
// time: O(n) + O(k) where k is min(size, m) and 
//       m is the size of the original allocation
char *pool_realloc(struct pool *p, char *addr, int size);

// pool_print_active(p) prints out a description of the active allocations 
//   in pool p using the following format:
//   "active: index1 [size1], index2 [size2], ..., indexN [sizeN]\n" or
//   "active: none\n" if there are no active allocations
//   where the index of an allocation is relative to the start of the pool
// effects: displays a message
// time: O(n)
void pool_print_active(struct pool *p);

// pool_print_available(p) prints out a description of the available 
//   contiguous blocks of memory still available in pool p:
//   "available: index1 [size1], index2 [size2], ..., indexM [sizeM]\n" or
//   "available: none\n" if all of the pool has been allocated
// NOTE: It is impossible for two blocks of available memory to be adjacent.
//       If two blocks are adjacent, they should be merged to be a single,
//       larger block. In other words: index_K+1 > index_K + size_K
// effects: displays a message
// time: O(n)
void pool_print_available(struct pool *p);
