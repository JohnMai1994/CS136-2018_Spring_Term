// SEASHELL_READONLY

// This is a Dictionary ADT that can store *ANY* kind of data
// with both keys and values as void pointers (void *)

// It allows you to select the key with index k (via dict_select)

// It returns the number of keys in O(1) (via dict_count)

// The running times given as O(h) correspond to the height of the
// underlying BST, which is hidden from the client.
// In the worst case, O(h) is O(n) and in the best case is O(logn)

struct dictionary;

// typedef: Dictionary ==> (struct dictionary *)
typedef struct dictionary *Dictionary;

// function typedefs:
  
// DictKeyCompare(key_a, key_b) uses the same convention as strcmp
//   to compare two keys
typedef int (*DictKeyCompare) (void *key_a, void *key_b);

// FreeFunction(obj) frees all memory associated with obj
typedef void (*FreeFunction) (void *obj);

// PrintKeyVal(key, val) prints out the key and value for dict_print
typedef void (*PrintKeyVal) (void *key, void *val);


// dict_create(cmp_function, free_key_function, free_val_function,
//             print_function) creates a new dictionary
//   (see above function typedefs for parameter descriptions)
// effects: allocates memory (client must call dict_destroy)
Dictionary dict_create(DictKeyCompare cmp_function,
                       FreeFunction free_key_function,
                       FreeFunction free_val_function,
                       PrintKeyVal print_function);

// dict_insert(key, val, d) inserts key/val pair into d
//   if key already exists then it frees both the old key and old value
// effects: modifies d, may free old key/value
// time:    O(h)
void dict_insert(void *key, void *val, Dictionary d);

// dict_lookup(key, d) finds the value corresponding to the key in d
//   or returns NULL if key does not exist
// time:    O(h)
void *dict_lookup(void *key, Dictionary d);

// dict_remove(key, d) removes (and frees) the key and value in d
//   if the key does not exist, the dictionary does not change
// effects: modifies d, frees key/value
// time:    O(h)
void dict_remove(void *key, Dictionary d);

extern const int PREORDER;
extern const int INORDER;
extern const int POSTORDER;

// dict_print(order, d) prints the dictionary in the given order
// notes: reveals the underlying BST structure
//        if the dictionary is empty, prints nothing
// requires: order is one of (PREORDER, INORDER, POSTORDER)
// effects:  displays output
// time:     O(n)
void dict_print(int order, Dictionary d);

// dict_select(k, d) finds the key with index k in d
// requires: 0 <= k < dict_count(d)
// time:     O(h)
void *dict_select(int k, Dictionary d);

// dict_count(d) returns the number of keys in d
// time: O(1)
int dict_count(Dictionary d);

// dict_destroy(d) frees all memory for d
// effects: d is no longer valid, all keys and values are freed
// time:    O(n)
void dict_destroy(Dictionary d);
