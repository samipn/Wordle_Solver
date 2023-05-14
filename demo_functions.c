// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif", "tense",
    "ultra", "vital", "ether", "nadir" };

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i=0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;
  
  char letter = 'r';
  int letter_scores[26];
  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }
  printf("here is the score of the letter: %d\n", score_letter(letter, vocabulary, num_words));
  printf("here is the score of the word: %d\n", score_word("stktk", letter_scores));
  printf("here is the best guess: %s\n", get_guess(vocabulary,num_words));
  printf("here is the number of filtered gray words: %zu\n", filter_vocabulary_gray(letter, vocabulary, num_words));
  printf("here is the number of filtered yellow words: %zu\n", filter_vocabulary_yellow(letter, 2, vocabulary, num_words));
  printf("here is the number of filtered green words: %zu\n", filter_vocabulary_green(letter, 4, vocabulary, num_words));

  free_vocabulary(vocabulary, num_words);
  
  return 0;
}
