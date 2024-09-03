#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main(int argc, char** argv) {
  FILE *fp;
  size_t size = 0;
  char *buffer = NULL;
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]");
    exit(1);
  }

  for (int i = 2; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }

    while (getline(&buffer, &size, fp) >= 0)
      if (strstr(buffer, argv[1]) != NULL)
        printf("%s", buffer);

    free(buffer);
    fclose(fp);
  }
}
