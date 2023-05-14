#include "command_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFSIZE 512
#define NUM_BUCKETS 10

int main() {
  char buff[BUFFSIZE];
  FILE* infile;
  infile = fopen("customers.tsv", "r");
  int count = 0;
  const char tab[2] = "\t";
  char *value;
  char inputs[4][100];
  char command[8];
  HashTable* buckets[NUM_BUCKETS] = {NULL};
  char *user_email = malloc(sizeof(char) * 10);
  while ((fgets(buff, BUFFSIZE, infile) != NULL)) {
    //printf("%s\n", buff);
    buff[strcspn(buff, "\n")] = 0;
    value = strtok(buff, tab);
    while (value != NULL) {
      if (count == 0) { //email
	strcpy(inputs[0], value);
        //printf("here is inputs 0, %s\n", inputs[0]);
	value = strtok(NULL, tab);
	count++;
      }
      else if (count == 1) { //name
        strcpy(inputs[1], value);
        //printf("here is inputs 1, %s\n", inputs[1]);
	value = strtok(NULL, tab);
	count++;
      }
      else if (count == 2) { //shoe size
        strcpy(inputs[2], value);
        //printf("here is inputs 2, %s\n", inputs[2]);
        value = strtok(NULL, tab);
	count++;
      }
      else if (count == 3) { //favorite food
        strcpy(inputs[3], value);
        //printf("here is inputs 3, %s\n", inputs[3]);
        value = strtok(NULL, tab);
	count++;
      }
      else {
	//size_t val = atoi(inputs[2]);
	//add_user_to_hashtable(inputs[0], inputs[1], val, inputs[3], buckets, NUM_BUCKETS);
	count = 0;
      }
    }
  }
  fclose(infile);

  while (true) {
    printf("Enter command:\n");
    fgets(command, 8, stdin);
    if (strcmp(command, "quit") == 10) {
      break;
    }
    else if (strcmp(command, "add") == 10) {
      printf("Enter email address:\n");
      char email[BUFFSIZE];
      fgets(email, BUFFSIZE, stdin);
      //printf("%s", email);
      
      printf("Enter display name:\n");
      char name[BUFFSIZE];
      fgets(name, BUFFSIZE, stdin);
      //printf("%s", name);
      
      printf("Enter favorite food:\n");
      char fav_food[BUFFSIZE];
      fgets(fav_food, BUFFSIZE, stdin);
      //printf("fav_food: %s", fav_food);

      printf("Enter shoe size:\n");
      int shoe_size;
      scanf("%d", &shoe_size);
      //printf("%d", shoe_size);
      add_user_to_hashtable(email, name, shoe_size, fav_food, buckets, NUM_BUCKETS);
    }
    else if (strcmp(command, "lookup") == 10) {
      printf("Enter email address to lookup:\n");
      //char *user_email = NULL;
      fgets(user_email, BUFFSIZE, stdin);
      lookup_email(user_email, buckets, NUM_BUCKETS);
    }
    else if (strcmp(command, "list") == 10) {
      FILE* infile;
      infile = fopen("customers.tsv", "r");
      char c = fgetc(infile);
      while (c != EOF) {
        printf("%c", c);
	c = fgetc(infile);
      }
    }
    else {
      printf("Unknown command\n");
    }
  }
  return 0; 
}
