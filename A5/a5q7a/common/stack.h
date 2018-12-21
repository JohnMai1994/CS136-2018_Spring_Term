#include <stdbool.h>

// SEASHELL_READONLY

// Stack: provides a Integer Stack ADT

struct stack;

// NOTE: ALL stack parameters must be valid stacks

// stack_create() creates a new empty stack
// effects: allocates memory (client must call stack_destroy)
struct stack *stack_create(void);

// stack_is_empty(s) determines if stack s is empty
bool stack_is_empty(const struct stack *s);

// stack_top(s) returns the top item in stack s
// requires: stack is not empty
int stack_top(const struct stack *s);

// stack_pop(s) returns and pops (removes) the top item in stack s
// requires: stack is not empty
int stack_pop(struct stack *s);

// stack_push(s) adds item to the top of stack s
void stack_push(int item, struct stack *s);

// stack_destroy(s) frees all memory for s
// effects: s is no longer valid
void stack_destroy(struct stack *s);
