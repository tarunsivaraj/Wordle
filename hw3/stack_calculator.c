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
  n1->item = item;
  n1->next = s->top;

  s->top = n1;

  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  if (s == NULL || s->top == NULL) {
    return false;
  }
  CalculatorItem result = s->top->item;
  *output = result;

  Node *delete_this = s->top;
  
  s->top = s->top->next;

  free(delete_this);

  delete_this = NULL;

  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  if(s == NULL || s->top == NULL) {
    return true;
  }
  return false;

}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  while((*s)->top != NULL) {
    Node *n2 = (*s)->top;
    (*s)->top = (*s)->top->next;
    free(n2);
    n2 = NULL;
  }
  free(*s);
  s = NULL;

}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  CalculatorItem x;
  CalculatorItem y;
  CalculatorItem res;

  printf("%u\n", item.type);

  if(item.type == ADD){
    stack_pop(s, &item);
    x.value = item.value;
    printf("the x value: %f\n", x.value);
    stack_pop(s, &item);
    y.value = item.value;
    printf("the y value: %f\n", y.value);
    res.value = y.value + x.value;
    res.type = NUMBER;
    stack_push(s, res);
    printf("%f\n", res.value);
    printf("%u\n", res.type);
  }
  else if(item.type == SUBTRACT){
    stack_pop(s, &item);
    x.value = item.value;
    printf("the x value: %f\n", x.value);
    stack_pop(s, &item);
    y.value = item.value;
    printf("the y value: %f\n", y.value);
    res.value = y.value - x.value;
    stack_push(s, res);
    printf("%f\n", res.value);
  }
  else if(item.type == MULTIPLY){
    stack_pop(s, &item);
    x.value = item.value;
    printf("the x value: %f\n", x.value);
    stack_pop(s, &item);
    y.value = item.value;
    printf("the y value: %f\n", y.value);
    res.value = y.value * x.value;
    stack_push(s, res);
    printf("%f\n", res.value);
  }
  else if(item.type == DIVIDE){
    stack_pop(s, &item);
    x.value = item.value;
    printf("the x value: %f\n", x.value);
    stack_pop(s, &item);
    y.value = item.value;
    printf("the y value: %f\n", y.value);
    res.value = y.value / x.value;
    stack_push(s, res);
    printf("%f\n", res.value);
  }
  else if (item.type == NUMBER){
    //x.value = item.value;
    printf("pushpushpush %f\n", item.value);
    stack_push(s, item);
    printf("pushpushpush %f\n", item.value);
  }
  else{
    return false;
  }
  return true;
}
