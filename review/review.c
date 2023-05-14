#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  *sum = a + b;
  if (a > b) {
    *difference = a - b;
  }
  else {
    *difference = b - a;
  }
}

// Problem 2

//Push helper function
void ll_push(LLint** top, int value) {
  LLint* node = (LLint*)malloc(sizeof(LLint));
  node->val = value;
  node->next = (*top);
  (*top) = node;
}

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  if (node == NULL) {
    return 0;
  }
  else {
    return ll_length(node->next) + 1;
  }
}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  int count = 0;
  LLint* curr = node;
  
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  return count;
}

// Problem 3.

//Stack push helper function thanks Prof. Rudnick
void stack_push(Stack *s, double item) {
  LLdouble *newtop = (LLdouble *)calloc(1, sizeof(LLdouble));
  if (newtop == NULL) {
    return;
  }
  newtop->val = item;
  newtop->next = s->top;
  s->top = newtop; 
}

//Stack pop helper function
double stack_pop(Stack *s, double *val) {
  if (s == NULL || s->top == NULL) {
    return 0;
  }
  
  double result = s->top->val;
  *val = result;
  LLdouble *delete_this = s->top;
  s->top = s->top->next;

  free(delete_this);
  return result;
}

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
  Stack *new_stack;
  new_stack = (Stack *)calloc(1, sizeof(Stack));
  for (size_t i = 0; i < array_len; i++) {
    stack_push(new_stack, array[i]);
    double result = stack_pop(new_stack, &array[i]);
    array[i] = result;
    for (size_t i = 0, high = array_len - 1; i < high; i++, high--) {
      double temp = array[i];
      array[i] = array[high];
      array[high] = temp;
    }
  } 
}

//Print array fucntion
void print_array(double *array, size_t array_len) {
  for (size_t i = 0; i < array_len; i++) {
    printf("%f\n", array[i]);
  }
}

// Problem 4.

//helper function from the book
/*struct tnode *talloc(void) {
  return (struct tode *) malloc(sizeof(struct tnode));
}

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  // Thanks to the book
  int cond;

  if(node == NULL) {
    node = talloc();
    node->word = strdup(word);
    node->count = 1;
    node->left = node->right = NULL;
  }
  else if ((cond = strcmp(word, node->word)) == 0) {
    node->count++;
  }
  else if (cond < 0) {
    node->left = word_observe(node->left, word);
  }
  else {
    node->right = word_observe(node->right, word);
  }
  return node;
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  return 0;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
}*/
