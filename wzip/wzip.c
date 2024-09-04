#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *fp;
  char buffer[2] = {0};
  char pattern[2] = {0};
  int j = 0;

  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; ++i) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wzip: cannot open file\n");
      exit(1);
    }

    while (fread(buffer, 1, 1, fp)) {
      if (strcmp(buffer, pattern) == 0)
        j++;
      else {
        if (pattern[0] != '\0') {
          fwrite(&j, 4, 1, stdout);
          fwrite(pattern, 1, 1, stdout);
        }
        j = 1;
        strcpy(pattern, buffer);
      }
  }
  fclose(fp);
 }
 fwrite(&j, 4, 1, stdout);
 fwrite(pattern, 1, 1, stdout);
 return 0;
}
