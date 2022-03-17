#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  int summ = a + b;
  int differencee = a - b;
  *sum = summ;
  *difference = differencee;

}

// Problem 2

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  int counter = 0;
  LLint *x = node;
  while(x != NULL) {
    counter++;
    x = x->next;
  }
  // change this, clearly.
  return counter;
}

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  // These are just default return values; they're for you to change.
  int counter = 0;
  if (node == NULL) {
    return 0;
  }else{
    return 1 + ll_length_iterative(node->next);
  }

  return counter;
}

// Problem 3.

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
  LLDouble *x;
  for(size_t a = 0; a < array_len; a++) {
    x = push(x, array[a]);
  }
  for(size_t b = 0; b < array_len; b++) {
    array[b] = pop(&x);
//    printf("%f\n", array[b]);
  }

}

LLDouble *push(LLDouble *s, double x ) {
  LLDouble *newnode = calloc(1, sizeof(LLDouble));
  if (s == NULL) {
    newnode->val = x;
    newnode->next = s;
    return newnode;
  }
  newnode->val = x;
  newnode->next = s;
  return newnode;
}


double pop(LLDouble **s) {
  if (*s == NULL) {
    return 0;
  }
  double y;
  y = (*s)->val;
  
  LLDouble *deletethis = *s;
  *s = (*s)->next;
  free(deletethis);
  return y;
}

// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  int condition = 0;
  if(node == NULL) {
    
    node = (tnode*)calloc(1, sizeof(tnode));
    node->word = strdup(word);
    node->count = 1;
    node->left = node->right = NULL;
  }

  else if((condition == strcmp(word, node->word)) == 0) {
    node->count++;
  }

  else if(condition < 0) {
    node->left = word_observe(word, node->left);
  }
  else{
    node->right = word_observe(word, node->right);
  }
  return node;
  }


int word_count(char *word, tnode *node) {
  int condition = 0;
  if(node == NULL) {
    return 0;
  }else if(condition == strcmp(word, node->word)) {
    return node->count;
  }

  else if(condition < 0) {
    return word_count(word, node->left);
  }
  else{
    return word_count(word, node->right);
  }
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
  if(node != NULL) {
    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
  }
}
