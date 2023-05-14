#include "command_util.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* typedef struct HashTable {
  char *email; //key
  char *name;
  int shoe_size;
  char *fav_food;
  struct HashTable *next;
} HashTable; */

#define NUM_BUCKETS 10

//Thank you Dan Bernstein
unsigned long hash(char *email) {
  unsigned long hash = 5381;
  int c;
  while (*email != '\0') {
    c = *email;
    hash = ((hash << 5) + hash) + (unsigned char)c;
    email++;
  }
  return hash;
}

//Thanks Professor Rudnick
HashTable *add_user_to_list(char *email, char *name, int shoe_size, char *food, HashTable *bucket) {
  HashTable* new_user;

  //add replacing values if email is already in hashtable
  new_user = malloc(sizeof(HashTable));
  new_user->email = strdup(email);
  new_user->name = strdup(name);
  new_user->shoe_size = shoe_size;
  new_user->fav_food = strdup(food);
  new_user->next = bucket;

  return new_user;
}

void add_user_to_hashtable(char *email, char *name, int shoe_size, char *food, HashTable **buckets, size_t num_buckets) {
  size_t which_bucket = hash(email) % num_buckets;
  buckets[which_bucket] = add_user_to_list(email, name, shoe_size, food, buckets[which_bucket]);
  printf("user %s goes in bucket %lu\n", email, which_bucket);
}

void *lookup_email(char *email, HashTable **buckets, size_t num_buckets) {
  size_t which_bucket = hash(email) % num_buckets;
  HashTable* node;
  node = buckets[which_bucket];
  while (node != NULL) {
    if (strcmp(node->email, email) == 0) {
      printf("%s\n", node->email);
      printf("%s\n", node->name);
      printf("%d\n", node->shoe_size);
      printf("%s\n", node->fav_food);
    }
    else {
      printf("Unable to find email address\n");
    }
    node = node->next;
  }
  return(0);
}
