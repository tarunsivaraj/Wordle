#include "final.h"

#include <stdio.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  *biggest = 0;
  *nextbiggest = 0;
  LLint *temp = linkedlist;
  while(temp != NULL) {
    printf("%d\n", temp->val);
    if(temp->val > *biggest) {
      *nextbiggest = *biggest;
      *biggest = temp->val;
    }
    else if(temp->val > *nextbiggest) {
      *nextbiggest = temp->val;
    }
    temp = temp->next;
  }
  return;
}