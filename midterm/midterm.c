#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// PROBLEM 1

long long *fibonacci_numbers(int n) {
  int i;
  long long fib[n+2];
  fib[0] = 1;
  fib[1] = 1;
  printf("%lld, ", fib[0]);
  printf("%lld, ", fib[1]);
  for (i = 2; i <= n; i++){
    fib[i] = fib[i-1] + fib[i-2];
    printf("%lld, ", fib[i]); 
  }
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 3, 5, 8, ...
  long long* output = NULL;
  return output;
}


// PROBLEM 2

typedef struct {
  int shoe_size;
  int customer_id;
  int num_purchases;
} ShoeCustomer;

void swap(int a, int b) {
  a = a ^ b;
  b = a ^ b;
  a = b ^ a;
}

void bubble_sort_customers(ShoeCustomer* customers, int n_customers) {
  // Your code here! Make them sorted!
  int x;
  int y;
  bool swapped;
  do {
    swapped = false;
    for (x = 1; x < n_customers; x++) {
      for(y = 1; y < n_customers; y += 2) {
        if (customers->shoe_size - 1 > customers->shoe_size) {
          swap(customers->shoe_size - 1, customers->shoe_size);
	  swapped = true;
        }
      } 	
    }
    n_customers--; 
  } while (swapped);
}

// PROBLEM 3

// A linked list of floating point numbers.
typedef struct LLfloat {
  float val;
  struct LLfloat *next;
} LLfloat;

LLfloat *map_floats(float (*f)(float), LLfloat *numbers)  {
  // finish this function.
  // Should it be recursive? It's up to you, but it could be recursive!
  if (numbers->next == NULL) {
    printf("List is empty");  
  }
  float i;
  for (i = 0; i < numbers->val; i++){
    float results = f(numbers->val);
    struct LLfloat* new_ll = (struct LLfloat*) malloc(sizeof(struct LLfloat));
    new_ll->val = results;
    new_ll->next = new_ll;
    printf("this is the ll %f", new_ll->val);
    free(new_ll);
  }
  return NULL;
}

// PROBLEM 4

unsigned long compute_availability(unsigned long *calendars, int num_users) {
  int i;
  for (i = 0; i < num_users; i++) {
    if (calendars[i] == 0) {
      return 0;
    }
    else {
      return *calendars;
    }
  }
  unsigned long availability = 0;
  return availability;
}

// put examples for testing your functions in the main! You're going to have to
// figure out how to test these.
int main(void) {
  return 0;
}
