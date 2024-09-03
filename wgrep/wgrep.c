#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char** argv) {
  FILE *fp;
  size_t size = 0;
  char *buffer = NULL;
  char buf[BUFFER_SIZE];
  char *result;
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }

  if (argc == 2) {
    while((result = fgets(buf, BUFFER_SIZE, stdin)) != NULL)
      if (strstr(result, argv[1]) != NULL)
        printf("%s", result);
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
