#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// This is an advanced I/O test of the dictionary module
// that creates a "dictionary of dictionaries":
// The master dictionary has strings for keys and
// dictionaries as values (called "language dictionaries")
// The "language dictionaries" have string keys and string values


// my_strdup(src) duplicates src as a new string
// requires: src is a valid string
// effect: allocates memory (must be free'd later)
// time: O(n), where n is the length of src
char *my_strdup(const char *src) {
  assert(src);
  char *dup = malloc((strlen(src) + 1) * sizeof(char));
  strcpy(dup, src);
  return dup;
}


// my_strcmp(a, b) is the same as strcmp but with void parameters
// requires: a, b are both valid (non-NULL) strings
// Time: O(n), where n is the shorter of the two strings
int my_strcmp(void *a, void *b) {
  const char *string_a = a;
  const char *string_b = b;
  return strcmp(string_a, string_b);
}


// free_dict(d) is a void wrapper for dict_destroy (see dict_destroy)
void free_dict(void *d) {
  Dictionary lang = d;
  dict_destroy(lang);
}


// language_print(key, val) prints out (key/value) pairs
// effects: displays output
void language_print(void *key, void *val) {
  const char *string_key = key;
  const char *string_val = val;
  if (string_val == NULL) {
    string_val = "NOT_IN_DICTIONARY";
  }
  printf("%s => %s\n", string_key, string_val);
}


// master_print(key, val) prints out the name of the dict (key)
//   and then the entire val dictionary
void master_print(void *key, void *val) {
  const char *s = key;
  Dictionary d = val;
  printf("===== DICTIONARY: %s [%d]\n", s, dict_count(d));
  dict_print(INORDER, d);
}

int main(void) {

  Dictionary master = dict_create(my_strcmp, free, free_dict, master_print);
  Dictionary lang = NULL;
  char command[21] = {0};
  char language[21] = {0};
  char keyword[81] = {0};
  char valword[81] = {0};

  while (scanf("%s", command) == 1 && strcmp(command, "exit")) {
    if (!strcmp(command, "print")) {
      dict_print(INORDER, master);
    } else if (!strcmp(command, "newdict")) {
      assert(scanf("%s", language) == 1);
      lang = dict_create(my_strcmp, free, free, language_print);
      dict_insert(my_strdup(language), lang, master);
    } else if (!strcmp(command, "freedict")) {
      assert(scanf("%s", language) == 1);
      dict_remove(language, master);
    } else if (!strcmp(command, "add")) {
      assert(scanf("%s", language) == 1);
      assert(scanf("%s", keyword) == 1);
      assert(scanf("%s", valword) == 1);
      lang = dict_lookup(language, master);
      assert(lang);
      dict_insert(my_strdup(keyword), my_strdup(valword), lang);
    } else if (!strcmp(command, "remove")) {
      assert(scanf("%s", language) == 1);
      assert(scanf("%s", keyword) == 1);
      lang = dict_lookup(language, master);
      assert(lang);
      dict_remove(keyword, lang);
    } else if (!strcmp(command, "lookup")) {
      assert(scanf("%s", language) == 1);
      assert(scanf("%s", keyword) == 1);
      lang = dict_lookup(language, master);
      assert(lang);
      printf("%s: ", language);
      language_print(keyword, dict_lookup(keyword,lang));
    } else {
      printf("unexpected command: %s\n", command);
      break;
    }
  }
  dict_destroy(master);
}
