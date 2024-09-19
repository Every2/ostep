#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
  int file  = open("test.txt", O_CREAT | O_RDWR);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    write(file, "worked\n", strlen("worked\n"));
    printf("%d\n", file);
  }
  else {
    write(file, "outside\n", strlen("outside\n"));
    printf("%d\n", file);
  }

  close(file);
}
