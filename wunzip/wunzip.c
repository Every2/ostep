#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char buffer[5] = {0};
  int j = 0;

  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wunzip: cannot open file\n");
      exit(1);
    }

    while (fread(&j, 4, 1, fp)) {
      memset(buffer, 0, strlen(buffer));
      fread(buffer, 1, 1, fp);
      for (int k = 0; k < j; k++)
        printf("%s", buffer);
    }
    fclose(fp);
  }

  return 0;
}
