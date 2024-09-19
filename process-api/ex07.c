#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    close(STDOUT_FILENO);
    printf("test\n");
  }
  return 0;
}
