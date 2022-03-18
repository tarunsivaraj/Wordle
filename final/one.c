#include "final.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t word_count(char *text) {
  size_t counter = 0;
  size_t x;

  for(x = 0; text[x] != '\0'; x++) {
    if (!((text[x] >= 'a' && text[x] <= 'z') || (text[x] >= 'A' && text[x] <= 'Z')) && ((text[x-1] >= 'a' && text[x-1] <= 'z') || (text[x-1] >= 'A' && text[x-1] <= 'Z'))) {
//      printf("%c\n", text[x]);
      counter++;
    }
  }
//  printf("%zu\n", x);
  if((text[x-1] >= 'a' && text[x-1] <= 'z') || (text[x-1] >= 'A' && text[x-1] <= 'Z')) {
//    printf("%zu\n", x);
    counter++;
  }
  
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.

  return counter;
}