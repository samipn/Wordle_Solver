#include "final.h"

#include <stdio.h>
#include <limits.h>

void find_two_biggest(LLint *linkedlist, int *biggest, int *nextbiggest) {
  int first = linkedlist->val;
  int second = linkedlist->next->val;
  int max = 0;
  int second_max = 0;
  if (first > second) {
    max = first;
  }
  else if(second > first) {
    max = second;
  }
  else {
    max = first;
  }
  if (first < second) {
    second_max = first;
  }
  else if (second < first) {
    second_max = second;
  }
  else {
    second_max = first;
  }
  //printf("max: %d\n", max);
  //printf("second max: %d\n", second_max);
  
  linkedlist = linkedlist->next->next;

  while (linkedlist != NULL) {
    if (linkedlist->val > max) {
      second_max = max;
      max = linkedlist->val;
    }
    else if (linkedlist->val > second_max) {
      second_max = linkedlist->val;
    }
    linkedlist = linkedlist->next;
  }

  *biggest = max;
  *nextbiggest = second_max;
  return;
}
