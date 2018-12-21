/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Jiadong Mai
// login ID: J4mai
/////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdlib.h>
#include "dictionary.h"
#include "cs136-trace.h"
#include <stdio.h>

/////// DO NOT MODIFY DATA STRUCTURES OR PRINT CONSTANTS

struct bstnode {
  void *item;                // key
  void *value;               // additional value (augmentation)
  struct bstnode *left;
  struct bstnode *right;
  int count;                 // *** new augmentation (see notes)
};

struct dictionary {
  struct bstnode *root;
  // function pointers
  DictKeyCompare key_compare;
  FreeFunction free_key;
  FreeFunction free_val;
  PrintKeyVal print_keyval;  
};

const int PREORDER = -1;
const int INORDER = 0;
const int POSTORDER = 1;

/////////////////////////////

Dictionary dict_create(DictKeyCompare cmp_function,
                       FreeFunction free_key_function,
                       FreeFunction free_val_function,
                       PrintKeyVal print_function) {
  Dictionary new_dictionary = malloc(sizeof(struct dictionary));
  new_dictionary->root = NULL;
  new_dictionary->key_compare = cmp_function;
  new_dictionary->free_key = free_key_function;
  new_dictionary->free_val = free_val_function;
  new_dictionary->print_keyval = print_function;
  return new_dictionary;
}

struct bstnode *new_leaf(void *key, void *val) {
  struct bstnode *leaf = malloc(sizeof(struct bstnode));
  leaf->item = key;
  leaf->value = val;
  leaf->left = NULL;
  leaf->right = NULL;
  leaf->count = 1;
  return leaf;
}

void insert_bstnode(void *key, void *val, struct bstnode *node,  
                    Dictionary d) {
  assert(d);
  int result = d->key_compare(key, node->item);
  if (result == 0) {
    d->free_key(node->item);
    node->item = key;
    d->free_val(node->value);
    node->value = val;
  } else if (result <0) {
    if (node->left) {
      if (dict_lookup(key, d) == NULL) node->count += 1;
      insert_bstnode(key, val, node->left, d);
    } else {
      if (dict_lookup(key, d) == NULL) node->count += 1;
      node->left = new_leaf(key, val);
      
    }
  } else if (node->right) {
    if (dict_lookup(key, d)== NULL) node->count += 1;
    insert_bstnode(key, val, node->right, d);
  } else {
    if (dict_lookup(key, d) == NULL) node->count += 1;
    node->right = new_leaf(key, val);
  }
}

void dict_insert(void *key, void *val, Dictionary d) {
  assert(d);
  struct bstnode *node = d->root;
  if (node) {
    insert_bstnode(key, val, node,  d);
  } else {
    d->root = new_leaf(key, val); 
  }
  
}


void *dict_lookup(void *key, Dictionary d) {
  assert(d);
  struct bstnode *node = d->root;
  while(node) {
    int result = d->key_compare(key, node->item);
    if (result == 0) {
      return node->value;
    } 
    if (result < 0) {
      node = node->left; 
    } else {
      node = node->right;
    }
  }
  return NULL;
}

struct bstnode *remove_bstnode(void *key, struct bstnode *node, Dictionary d) {
  assert(d);
  if (node == NULL) return NULL;
  int result = d->key_compare(key, node->item);
  if (result < 0) {
    if (dict_lookup(key, d) != NULL) node->count -= 1;
    node->left = remove_bstnode(key, node->left,d);
  } else if (result > 0) {
    if (dict_lookup(key, d) != NULL) node->count -= 1;
    node->right = remove_bstnode(key, node->right,d);
  } else if (node->left == NULL) {
    if (dict_lookup(key, d) != NULL) node->count -= 1;
    struct bstnode *new_root = node->right;
    d->free_val(node->value);
    d->free_key(node->item);
    free(node);
    return new_root;
  } else if (node->right == NULL) {
    if (dict_lookup(key, d) != NULL) node->count -= 1;
    struct bstnode *new_root = node->left;
    d->free_val(node->value);
    d->free_key(node->item);
    free(node);
    return new_root;
  } else {
    struct bstnode *next = node->right;
    struct bstnode *parent_of_next = NULL;
    while (next->left) {
      parent_of_next = next;
      next = next->left;
    }
    d->free_val(node->value);
    d->free_key(node->item);
    node->item = next->item;
    node->value = next->value;
    if (parent_of_next) {
      parent_of_next->left = next->right;
    } else {
      node->right = next->right;
    }
    free(next);
  }
  return node;
}


void dict_remove(void *key, Dictionary d) {
  assert(d);
  struct bstnode *node = d->root;
  d->root = remove_bstnode(key, node,d);  
}

void print_fun(int order, struct bstnode *node, PrintKeyVal print_keyval){
  if (node){
    if (order == -1) {
      print_keyval(node->item, node->value);
      print_fun(order, node->left, print_keyval);
      print_fun(order, node->right, print_keyval);
    } else if (order == 0){
      print_fun(order, node->left, print_keyval);
      print_keyval(node->item, node->value);
      print_fun(order, node->right, print_keyval);
    } else {
      print_fun(order, node->left, print_keyval);
      print_fun(order, node->right, print_keyval);
      print_keyval(node->item, node->value);
    } 
  }
}



void dict_print(int order, Dictionary d) {
  assert(d);
  struct bstnode *node = d->root;
  print_fun(order, node, d->print_keyval); 
}


void *select_node(int k, struct bstnode *node) {
  assert(node && 0 <= k && k < node->count);
  int left_count = 0;
  if (node->left) left_count = node->left->count;
  if (k < left_count) return select_node(k, node->left);
  if (k == left_count) return node->item;
  return select_node(k - left_count - 1, node->right);
}

void *dict_select(int k, Dictionary d) {
  assert(d);
  return select_node(k, d->root);
}


int dict_count(Dictionary d) {
  assert(d);
  struct bstnode *node = d->root;
  return node->count;
}



void free_bstnode(struct bstnode *node,FreeFunction free_key, 
                  FreeFunction free_val ) {
  if (node) {
    free_bstnode(node->left, free_key, free_val);
    free_bstnode(node->right, free_key, free_val);
    free_key(node->item);
    free_val(node->value);
    free(node);
  }
}

void dict_destroy(Dictionary d) {
  free_bstnode(d->root, d->free_key, d->free_val);
  free(d);

}
