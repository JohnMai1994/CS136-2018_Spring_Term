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
// login ID: j4mai
/////////////////////////////////////////////////////////////////////////////
#include "cs136-trace.h"
#include <assert.h>
#include <stdio.h>

// create_art(count, symbol, len) print the character in symbol[] and times in
//   count[]
// requires: count[] and symbol[] is vaild
//           len>= 0
// effects: produce output
void create_art(int count[], char symbol[], int len) {
  assert(count);
  assert(symbol);
  assert(len>0);
  
  for (int i = 0; i<len; ++i) {
    char sym_to_print = symbol[i];
    int times_to_print = count[i];
    for (int j = 0; j<times_to_print; ++j) {
      printf("%c", sym_to_print);
    }
  }
}

// read_art(count, symbol, len) reads the input and mutated the two array, count
//     and symbol by the order of input
// requires: count[] and symbol[] is vaild
//           len >= 0
// effects: read inputs
//          mutates count[] and symbol[]
int read_art(int count[], char symbol[], int len) {
  assert(count);
  assert(symbol);
  assert(len>0);
  char a;
  int length =0;
  while(1){
    int stop_side = scanf("%c", &a);
    if(stop_side!=1){
      break;
    }
      
    if (length ==0 && symbol[length] == 0) {
      symbol[length] = a;
      count[length] = 0;
    } 
    
    if (a != symbol[length]) {
      ++length;
      count[length] = 1;
      symbol[length] = a;
    } else{
      count[length] +=1;  
    }
      
  }
  return (length +1);
}

void bonus(int count[], char symbol[], int len) { 
  
  //int acount[60] = {2,5,3,1,8,2,4,2,2,1,4,1,5,1,7,1,5,1,4,1,4,1,5,1,6,1,5,1,5,
  //                  1,4,1,5,1,6,1,6,1,4,1,4,1,5,1,7,1,6,2,2,1,2,5,3,5,4,2,3,3,
  //                  2,1};
  //char asymbol[60] = {' ','+',' ','+',' ','+',' ','+',' ','\n',
  //              ' ','+',' ','+',' ','+',' ','+',' ','\n',
  //              ' ','+',' ','+',' ','+',' ','+',' ','\n',
  //              ' ','+',' ','+',' ','+',' ','+',' ','\n',
  //              ' ','+',' ','+',' ','+',' ','+',' ','\n',
  //              ' ','+',' ','+',' ','+',' ','+',' ','\n'};
  create_art(count, symbol, len);
  
}

int main(void) {
  //int count[7] = {1, 7, 1, 1, 3, 3, 1};
  //char symbol[7] = {'+', '-', '+', '\n', 'A', 'a', '\n'};
  //int len = 7;
  int count[1000] = {0};
  char symbol[1000] = {0};
  int len = read_art(count,symbol,1000);
  assert(count[0]==1);
  assert(count[4]==3);
  assert(symbol[2]=='+');
  trace_int(len)
  create_art(count,symbol,len);
  
  int bonus_count[10000]={0};
  char bonus_symbol[10000] = {0};
  int bonus_len = read_art(bonus_count,bonus_symbol,100);
  bonus(bonus_count, bonus_symbol, bonus_len);

}