#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFSIZE 512

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
  FILE* infile;
  char buff[BUFFSIZE];
  if (argc != 2) {
    fprintf(stderr, "usage: ./yelling <txt file>\n");
    exit(1);
  }
  infile = fopen(argv[1], "r"); 
  //fgetc(stdin);
  while ((fgets(buff, BUFFSIZE, infile) != NULL)) {
    buff[strcspn(buff, "\n")] = 0;
    for(int i = 0; buff[i] != '\0'; i++) {
      if(buff[i] >= 'a' && buff[i] <= 'z') {
        buff[i] = buff[i] - 32;
      }
    }
    printf("%s\n", buff);
  }
  fclose(infile);
  return 0;
}
