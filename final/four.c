#include "final.h"

#include <stdio.h>
#include <string.h>

// YOUR CODE GOES IN THIS FUNCTION!! Probably don't change the other ones.
WordCountTable *sum_word_count_tables(WordCountTable *table_a,
                                      WordCountTable *table_b) {
  /*size_t i = 0;
  size_t j = 0;
  if (table_a->num_buckets > table_b->num_buckets) {
    WordCountTable *union_table = build_word_count_table(table_a->num_buckets);  
  }
  else if (table_b->num_buckets > table_a->num_buckets) {
    WordCountTable *union_table = build_word_count_table(table_b->num_buckets);
  }
  else {
    WordCountTable *union_table = build_word_count_table(table_a->num_buckets);
  }

  while (i < table_a->num_buckets && j < table_b->num_buckets) {
    if (table_a->buckets->word < table_b->buckets->word) {
      set_word_count()
    }
  }
  return union_table;*/
  WordCountTable *out = build_word_count_table(table_a->num_buckets);
  size_t buckets = table_b->num_buckets;
  printf("number of buckets in table b: %zu\n", buckets);
  set_word_count("rutabaga", 101, out); 
  return out;
} 

//// more functions, table infrastructure. Please don't change these.

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

WordCountNode *set_word_count_in_list(char *word, int count,
                                      WordCountNode *bucket) {
  WordCountNode *new_node;

  new_node = malloc(sizeof(WordCountNode));
  new_node->word = strdup(word);
  new_node->count = count;
  new_node->next = bucket;
  return new_node;
}

void set_word_count(char *word, int count, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  // We're going to "overwrite" the previous value here (if it exists) by simply
  // putting a new value at the front of the linked list in the appropriate
  // bucket. This is faster and simpler, but will use more memory.
  table->buckets[which_bucket] =
      set_word_count_in_list(word, count, table->buckets[which_bucket]);
}

// Construct an empty WordCountTable.
WordCountTable *build_word_count_table(size_t num_buckets) {
  WordCountTable *out;

  out = calloc(1, sizeof(WordCountTable));
  out->num_buckets = num_buckets;

  // bunch of NULL pointers to WordCountNode.
  out->buckets = calloc(num_buckets, sizeof(WordCountNode *));
  return out;
}

int get_word_count_in_list(char *word, WordCountNode *node) {
  if (node == NULL) {
    return 0;
  }

  if (strcmp(word, node->word) == 0) {
    return node->count;
  }
  return get_word_count_in_list(word, node->next);
}

int get_word_count(char *word, WordCountTable *table) {
  size_t which_bucket = hash(word) % table->num_buckets;

  return get_word_count_in_list(word, table->buckets[which_bucket]);
}