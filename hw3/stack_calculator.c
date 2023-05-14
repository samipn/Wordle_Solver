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
  Node *current_top = (Node *)calloc(1, sizeof(Node));
  if (current_top == NULL) {
    return false;
  }
  current_top->item = item;
  current_top->next = s->top;
  s->top = current_top;
  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  if (s == NULL || s->top == NULL) {
    return false;
  }
  CalculatorItem res = s->top->item;
  *output = res;
  Node *temp = s->top;
  s->top = s->top->next;
  free(temp);
  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  if (s->top == NULL) {
    return true;
  }
  else {
    return false;  
  }
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
 struct Node* temp;
 while ((*s)->top != NULL) {
   temp = (*s)->top;
   (*s)->top = temp->next;
   free(temp);
 }
 s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  CalculatorItem result;
  if (item.type == NUMBER) {
    return stack_push(s, item);
  }
  else if (item.type == ADD) {
    CalculatorItem first_num;
    bool success = stack_pop(s, &first_num);
    if (success == false) {
      return false;
    }
    CalculatorItem second_num;
    bool success_two = stack_pop(s, &second_num);
    if (success_two == false) {
      return false;
    }
    result.value = first_num.value + second_num.value;
    stack_push(s, result);
    return true;  
  }
  else if (item.type == SUBTRACT) {
    CalculatorItem first_num;
    bool success = stack_pop(s, &first_num);
    if (success == false) {
      return false;
    }
    CalculatorItem second_num;
    bool success_two = stack_pop(s, &second_num);
    if (success_two == false) {
      return false;
    }
    result.value = second_num.value - first_num.value;
    stack_push(s, result);
    return true;
  }
  else if (item.type == MULTIPLY) {
    CalculatorItem first_num;
    bool success = stack_pop(s, &first_num);
    if (success == false) {
      return false;
    }
    CalculatorItem second_num;
    bool success_two = stack_pop(s, &second_num);
    if (success_two == false) {
      return false;
    }
    result.value = first_num.value * second_num.value;
    stack_push(s, result);
    return true;
  }
  else if (item.type == DIVIDE) {
    CalculatorItem first_num;
    bool success = stack_pop(s, &first_num);
    if (success == false) {
      return false;
    }
    CalculatorItem second_num;
    bool success_two = stack_pop(s, &second_num);
    if (success_two == false) {
      return false;
    }
    if (first_num.value == 0) {
      return false;
    }
    result.value = second_num.value / first_num.value;
    stack_push(s, result);
    return true;
  }
  else {
    return false;
  }
}
