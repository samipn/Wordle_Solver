#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct HashTable {
  char *email; //key
  char *name;
  int shoe_size;
  char *fav_food;
  struct HashTable *next;
} HashTable;

HashTable *add_user_to_list(char *email, char *name, int shoe_size, char *food, HashTable *bucket);

void add_user_to_hashtable(char *email, char *name, int shoe_size, char *food, HashTable **buckets, size_t num_buckets);

void *lookup_email(char *email, HashTable **buckets, size_t num_buckets);
