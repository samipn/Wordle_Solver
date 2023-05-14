#include "final.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

size_t word_count(char *text) {
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
  int i = 0;
  int total_words = 1;
  
  if (text[i] == '\0') {
    total_words = 0;
    return total_words;
  }

  while (text[i] != '\0') {
    if ((text[i] == ' ' && (text[i+1] >= 'a' && text[i+1] <= 'z')) || (text[i+1] >= 'A' && text[i+1] <= 'Z')) {
      total_words++;
    }
    i++;
  }
  return total_words;
}
