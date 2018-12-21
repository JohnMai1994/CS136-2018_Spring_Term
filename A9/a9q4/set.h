#include <stdbool.h>

// Set: provides a Set ADT for ints
// NOTE: ALL set parameters must be valid

struct set;

// set_create() returns a new empty set
// effects: allocates memory (caller must call set_destroy)
// time: O(1)
struct set *set_create(void);

// set_destroy(s) frees all dynamically allocated memory 
// effects: the memory at s is invalid (freed)
// time: O(1)
void set_destroy(struct set *s);

// set_size(s) returns the number of elements in s
// time: O(1)
int set_size(const struct set *s);

// set_member(s, i) determines if i is in set s
// time: O(log n) where n is set_size(s)
bool set_member(const struct set *s, int i);

// set_add(s, i) adds i to the set s, if it does not already contain i
// effects: s may be modified
// time: O(n) where n is set_size(s)
void set_add(struct set *s, int i);

// set_remove(s, i) removes i from s.  if i is not in s, s isn't changed
// effects: s may be modified
// time: O(n) where n is set_size(s)
void set_remove(struct set *s, int i);

// set_union(s1, s2) returns a new set that is the union of s1 and s2
// effects: allocates memory for the new set (caller must call set_destroy)
// time: O(n) where n is set_size(s1) + set_size(s2)
struct set *set_union(const struct set *s1, const struct set *s2);

// set_intersect(s1, s2) returns a new set that is the intersection of s1 and s2
// effects: allocates memory for the new set (caller must call set_destroy)
// time: O(n) where n is set_size(s1) + set_size(s2)
struct set *set_intersect(const struct set *s1, const struct set *s2);

// array_to_set(a, len) returns a new set that is all the unique elements of a
// requires: len > 0
// effects: allocates memory for the new set (caller must call set_destroy)
// time: O(n log n) where n is set_size(s)
struct set *array_to_set(const int a[], int len);

// set_to_array(s) returns a new array that is the elements of s
// in ascending order, or NULL if s is empty
// effects: may allocate memory for a new array (caller must call free)
// time: O(n)
int *set_to_array(const struct set *s);

// set_print(s) prints the elements of set s in ascending order
// using the format: 
// "[element_smallest,element_next,...,element_largest]\n"
// or "[empty]\n"
// effects: prints to output
// time: O(n)
void set_print(const struct set *s);
