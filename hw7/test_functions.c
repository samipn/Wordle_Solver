#include "command_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NUM_BUCKETS 10

int main(void){

  HashTable* buckets[NUM_BUCKETS] = {NULL};

  add_user_to_hashtable("saniraul@ucsc.edu", "Samip", 10, "Thai Food", buckets, NUM_BUCKETS);
  //add_user_to_hashtable("bernardo@google.com", "Bernardo", 12, "Any Food", buckets, NUM_BUCKETS);
  //add_user_to_hashtable("bernardo@google.com", "Bernardo", 12, "Any Food", buckets, NUM_BUCKETS);
  add_user_to_hashtable("henrietta1@google.com", "Henrietta", 8, "Pasta", buckets, NUM_BUCKETS);

  lookup_email("saniraul@ucsc.edu", buckets, NUM_BUCKETS);
  return 0;
}
