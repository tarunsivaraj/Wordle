#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  Node *n1 = (Node *)calloc(1, sizeof(Node));
  if (s == NULL || (s->top == NULL)) {
    return false;
  }
  n1->value = item;
  n1->next = s->top;

  s->top = n1;

  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  if (s == NULL || (s->top == NULL)) {
    return false;
  }
  int result = s->top->value;
  *output = result

  Node *delete_this = s->top
  free(delete_this)

  s->top = s->top->next

  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  if(s->top == 0) {
    return true;
  }
  return false;

}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  if (*s && (*s)->next) {
    free((*s)->next);
    free(*s);
    *s = NULL;
  }
  return;

}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
  return true;
}
