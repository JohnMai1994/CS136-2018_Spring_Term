#include <stdbool.h>

// Stack: provides a Stack ADT for int
// NOTE: ALL stack parameters must be valid
// n always stands for the number of items in the stack

struct stack;

// stack_create() creates a new empty stack
// effects: allocates memory (client must call stack_destroy)
// time: O(1)
struct stack *stack_create(void);

// stack_is_empty(s) determines if the stack s is empty
// time: O(1)
bool stack_is_empty(const struct stack *s);

// stack_top(s) returns the top item in the stack s
// requires: s is not empty
// time: O(1)
int stack_top(const struct stack *s);

// stack_pop(s) returns and removes the top item in the stack s
// requires: s is not empty
// time: O(1)
int stack_pop(struct stack *s);

// stack_push(s) adds item to the top of the stack s
// time: O(1)
void stack_push(int item, struct stack *s);

// stack_destroy(s) frees all memory for the stack s
// effects: s is no longer valid
// time: O(1)
void stack_destroy(struct stack *s);

// stack_print(s) prints the contents of the stack s
// effects: prints to output
// time: O(n)
void stack_print(const struct stack *s);
