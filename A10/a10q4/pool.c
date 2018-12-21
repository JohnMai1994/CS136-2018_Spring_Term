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

#include "pool.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "cs136-trace.h"
#include <string.h>



struct dllnode{
  char *address;
  int size;
  struct dllnode *next;
};

struct pool{
  int len;
  struct dllnode *root;
  char *begin;
  char *tail;
};

struct dllnode *create_node(char *address,int size){
  struct dllnode *new_node =malloc(sizeof(struct dllnode));
  new_node->address = address;
  new_node->size =size;
  new_node->next = NULL;
  return new_node;
}


struct pool *pool_create(int size){
  assert(size>=0);
  struct pool *new_node = malloc(sizeof(struct pool));
  new_node->len = size;
  new_node->begin = malloc(sizeof(char)*size);
  new_node->tail = new_node->begin + size;
  new_node->root = NULL;
  return new_node;
}


bool pool_destroy(struct pool *p){
  assert(p);
  assert(p->root);
  trace_int(p->root->size);
  free(p->begin);
  free(p->root);
  free(p);
  return true;
}

int size_fun(struct pool *p){
  struct dllnode *node = p->root;
  int count = 0;
  while (node) {
    count += node->size;
    node = node->next;
  }

  return count;
}


char *pool_alloc(struct pool *p, int size){
  trace_int(size);
  assert(p);
  assert(size>= 0);

  if (!p->root){
    p->root = create_node(p->begin, size);
    return p->begin;
  } 
  struct dllnode *node = p->root;
  struct dllnode *prevnode = p->root;
  if (!node->next){
    node->next = create_node(node->address + node->size, size); 
    return node->next->address;
  }
  int count = size_fun(p);
  if (count + size > p->len) {
    trace_int(1);
    return NULL;

  }
  while (node){
    node = node->next;
    if (node->address - prevnode->address - prevnode->size >= size){
      prevnode->next = create_node(prevnode->address+prevnode->size,size);
      prevnode->next->next = node;
    }
    prevnode = node;
    node = node->next;
  }

  if (p->tail - prevnode->address >= size){
    prevnode->next = create_node(prevnode->address+prevnode->size, size);
    return prevnode->address;
  }
  return NULL;
}

bool pool_free(struct pool *p, char *addr) {
  if (!p->root) return false;
  struct dllnode *node = p->root;
  struct dllnode *prevnode = p->root;

  if (p->root->address == addr){

    p->root = p->root->next;
    free(node);
    return true;
  }
  if (node->next){
    node = node->next;
    while (node){
      if (node->address == addr){
        prevnode->next = prevnode->next->next;
        free(node);
        return true;
      }
      prevnode = node;
      node = node->next;
    }
  }
  return true;
}



bool addr_exist(struct pool*p, char *addr){
  struct dllnode *node = p->root; 
  while(node){
    if (node->address == addr){
      return true; 
    }
    node = node->next;
  }
  return false;
}

bool space_enough(struct pool *p, struct dllnode *prevnode, 
                  struct dllnode *node, struct dllnode *nextnode, int size){
  if ((!nextnode)&&(!prevnode)){
    if (node->size >= size) return true;
    return false;
  } 
  if (!nextnode){
    if (p->tail - prevnode->address + prevnode->size>= size) return true;
    return false;
  }
  if (!prevnode){
    if (nextnode->address - node->address + node->size>= size) return true;
    return false;
  }

  if ((nextnode)&&(prevnode)) {
    if (nextnode->address - prevnode->address >= size){
      return true; 
    }
    return false;
  }
  return false;
}

char *pool_realloc(struct pool *p, char *addr, int size){

  if (!p->root)  return NULL;

  if (!addr_exist(p,addr)) return NULL;
  struct dllnode *node = p->root;
  struct dllnode *prevnode = p->root;


  if (node->address != addr){ 
    node = node->next;
    while (node){
      if (node->address == addr) break; 
      prevnode = node;
      node = node->next;
    }
  }
  char * array;
  if (node->address + node->size == 0){
    array = malloc(node->size * sizeof(char));
    strcpy(array, node->address);
  }
  if (node == prevnode){
    if (space_enough(p, NULL, node, node->next, size)) {
      prevnode->next = create_node(prevnode->address+prevnode->size, size);
      prevnode->next->next = node->next;
      free(node);
      return prevnode->next->address;
    } else{
      p->root = node->next;
      free(node); 
    }
  } else {
    assert(node->next == NULL);
    trace_int(1);
    if (space_enough(p, prevnode, node, node->next, size)) {
      prevnode->next = create_node(prevnode->address+prevnode->size, size);
      prevnode->next->next = node->next;
      free(node);
      return prevnode->next->address;
    }else{
      prevnode->next = node->next;
      free(node); 
    }
  }
  char * new_address =  pool_alloc(p, size);
  if (array){
    strcpy(new_address, array);
    free(array);
  }
  return new_address;
}

void pool_print_active(struct pool *p){
  printf("active: ");
  if (!p->root) {
    printf("none\n"); 
  } else {
    int size = 0 ;
    struct dllnode *node = p->root;
    trace_int(1);
    while (node){
      printf("%d [%d]", size, node->size);
      if (node->next) printf(", ");
      if (!node->next) printf("\n");
      size += node->size;
      node = node->next;
    }
  }
}

void pool_print_available(struct pool *p){
  printf("available: ");
  if (p->root) {
    int count = 0;
    struct dllnode *cal = p->root;

    while (cal){

      count += cal->size;
      cal = cal->next;
    }

    if (count == p->len){
      trace_int(count);
      printf("none\n");
    } else{
      struct dllnode *node = p->root;
      if (node->address != p->begin){
        int node_dis = node->address - p->begin;
        printf("%d [%d]", 0, node_dis);
      } else {
        while (node){
          int node_dis = node->address - p->begin;
          int next_dis;
          if (node->next) {
            next_dis = node->next->address - p->begin;
          } else {
            next_dis = p->tail - node->address + node->size;
          }

          printf("%d [%d]", node_dis + node->size, 
                 next_dis);
          node = node->next;
        }
      }
    }
  } else {
    printf("%d [%d]\n", 0, p->len);
  }
  trace_int(1);
}






/*


void pool_print_active(struct pool *p){
  assert(p);
  assert(p->act);
  assert(p->root);
  if(p->act->start){
    struct dllnode *tar = p->act->start;
    int index = tar->address - p->root;
    printf("active: %d [%d]",index,tar->size);
    while(tar->next){
      tar = tar->next;
      index = tar->address - p->root;
      printf(", %d [%d]",index,tar->size);
    }
    printf("\n");
  }else{
    printf("active: none\n");
  }   
}


void pool_print_available(struct pool *p){
  assert(p);
  assert(p->act);
  assert(p->root);
  struct dllnode *af = p->act->start;
  printf("available: ");
  int count = 0;
  while (af){
    count += af->size;
    af = af->next;
  }

  if (p->len == count) {
    printf("none\n");
  } else {
    if(!af){
      printf("0 [%d]\n",p->len);
    }else{
      char *pos = p->root;
      int between = af->address - pos;
      while((between<=0)&&(af->next)){
        pos = af->address + af->size;
        af = af->next;
        between = af->address -pos;
      }
      int index = pos - p->root;
      if(between>0){
        printf("available: %d [%d]",index,between);
        while(af->next){
          pos = af->address +af->size;
          af = af->next;
          int index = pos - p->root;
          between = af->address - pos;
          if(between>0){
            printf(", %d [%d]",index,between);
          }
        }
        pos = af->address+af->size;
        between = (p->root +p->len) - pos;
        int index = pos - p->root;
        if(between>0){
          printf(", %d [%d]\n",index,between);
        }else{
          printf("\n");
        }
      }else{
        pos = af->address + after->size;
        between = (p->root +p->len) - pos;
        int index = pos - p->root;
        if(between>0){
          printf("available: %d [%d]\n",index,between);
        }    
      }
    }
  }
}

*/

