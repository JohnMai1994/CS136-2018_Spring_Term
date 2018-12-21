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

#include <stdlib.h>
#include "trie.h"
#include  <stdio.h>
#include <assert.h>
#include <string.h>
#include "cs136-trace.h"


struct trie *trie_create(void) {
  struct trie *trie = malloc(sizeof(struct trie));
  trie->root = NULL;
  return trie;
}

struct trienode *new_trienode(void){
  struct trienode *new_node = malloc(sizeof(struct trienode));
  new_node->word_end = false;
  for (int i = 0; i < 26; ++i){
    new_node->children[i] = NULL; 
  }
  return new_node;
}

// char_to_index(char s) swap the char s into the position that should be,
//    'a' should equal to 0
int char_to_index(char s){
  return s - 97; 
}


void trie_add(const char *s, struct trie *t) {
  //char character = *s;
  assert(t);
  int i = 0;
  int index;
  if (t->root == NULL) {
    t->root = new_trienode();
  }
  struct trienode *trienode = t->root;
  while (s[i]){
    index = char_to_index(s[i]);
    if (trienode->children[index] == NULL) {
      trienode->children[index] = new_trienode();
    }
    trienode = trienode->children[index];

    ++i;
  }
  trienode->word_end = true;

}

// leaftrienode(struct trienode * trienode) return true if the
//    trienode->word_end is true
bool leaftrienode(struct trienode * trienode){
  assert(trienode);
  return (trienode->word_end != false); 
}

// isitfreetrienode(struct trienode * trienode) return true if the trienode
//    does not have other children
bool isitfreetrienode(struct trienode * trienode){
  int i;
  assert(trienode);

  for (i = 0; i < 26; ++i){
    if (trienode->children[i]) return false;
  }
  return true;
}

// 
bool trienode_remove(const char *s, struct trienode *trienode, 
                     int level, int len){
  assert(trienode);
  assert(level>= 0);
  assert(len>= 0);
  if (trienode){
    if (level == len ){  //len +1
      if (trienode->word_end) {
        trienode->word_end = false; 
        if (isitfreetrienode(trienode)){
          return true;
        }
        return false;
      }
    } else {
      int index = char_to_index(s[level]);;
      if (trienode_remove(s, trienode->children[index], level+1, len)){
        free(trienode->children[index]);
        trienode->children[index] = NULL;
        return ((leaftrienode(trienode))&&(isitfreetrienode(trienode)));
        // should not be ! above
      }
    }
  }
  return false;
}


void trie_remove(const char *s, struct trie *t) {
  assert(t);
  int len = strlen(s);
  if ((t->root) && (len >0)){
    trienode_remove(s, t->root, 0, len); 
  }
  if (t->root && len == 0){
    t->root->word_end = false;   
  }

  if (t->root && isitfreetrienode(t->root)){
     free(t->root);
  }
  
  // check if len == 0 and we need to remove root
  // also check if that function returns true and then remove root
}


bool trie_lookup(const char *s, const struct trie *t) {
  assert(t);
  int i = 0;
  if (t->root == NULL) return false;
  int index;
  struct trienode *trienode = t->root;
  while (s[i]){
    index = char_to_index(s[i]);
    if (trienode->children[index] == NULL){ 
      return false;
    }
    trienode = trienode->children[index];
    ++i;
  }
  return trienode->word_end;

}

void trienode_destroy(struct trienode *trienode){
  assert(trienode);
  for (int i = 0; i < 26; ++i){
    if (trienode->children[i] == NULL) continue;
    trienode_destroy(trienode->children[i]);
  }
  free(trienode);
}


void trie_destroy(struct trie *t) {
  assert(t);
  if (t->root){
    struct trienode *trienode = t->root;
    trienode_destroy(trienode);
  }
  free(t);
}

// char_to_index(char s) swap the int i into the character that should be,
//    0 should equal to 'a'
char index_to_char(int i){
  return i + 97; 
}

// trienode_print(struct trienode *trienode, char *str, int level) print the 
//  all the words in the trienode;
void trienode_print(struct trienode *trienode, char *str, int level){
  assert(trienode);
  if (trienode->word_end) {
    printf("%s\n", str); 
  }
  for (int i = 0; i < 26; ++i){
    if (trienode->children[i] == NULL) continue;
    char *str2 = malloc((strlen(str) + 2) *sizeof(char));
    strcpy(str2, str);
    str2[level++] = index_to_char(i);
    str2[strlen(str)+ 1] = 0;
    trienode_print(trienode->children[i], str2, level);
  }
  free(str);
}


void trie_print(const struct trie *t) {
  assert(t);
  if (t->root){
    char *string = malloc(sizeof(char));
    string[0] = 0;
    int level = 0;
    trienode_print(t->root, string, level);
  }
}

// trie_to_trienode(struct trienode *node, char *str, char **list, int *count)
//    put the trienode into the array.
void trie_to_trienode(struct trienode *node, char *str, char **list, 
                      int *count){
  if(node->word_end == true) {
    char *str2 = malloc((strlen(str) + 1) *sizeof(char));
    strcpy(str2, str);
    str2[strlen(str)] = 0;
    list[*count] = str2;
    (*count) ++;

  }

  for (int i = 0; i < 26; ++i){
    if (node->children[i] != NULL) {
      char *str3 = malloc((strlen(str) + 2) *sizeof(char));
      strcpy(str3, str);
      str3[strlen(str)] = index_to_char(i);
      str3[strlen(str) + 1] = 0;
      trie_to_trienode(node->children[i],str3, list, count);
    }
  }
  free(str);

}


char **trie_to_aos(const struct trie *t) {
  int count = 0;
  char *string = malloc(sizeof(char));
  string[0] = 0;
  char **list = malloc(trie_count(t) * sizeof(char *));
  trie_to_trienode(t->root, string ,list, &count);
  return list;
}


// trienode_count(struct trienode *trienode, int *count) return the number 
//   of the word_end in the trienode
void trienode_count(struct trienode *trienode, int *count){
  if (!trienode) return;
  if (trienode->word_end) ++(*count);
  for (int i = 0; i < 26; ++i){
    if (trienode->children[i] == NULL) continue;
    trienode_count(trienode->children[i], count);
  }

}


int trie_count(const struct trie *t) {
  assert(t);
  int count = 0;
  if (t->root == NULL) return count;
  struct trienode *trienode = t->root;
  trienode_count(trienode, &count);
  return count;
}
