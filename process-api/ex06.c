#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    printf("Hello\n");
  } else {
    waitpid(-1, &status, 0);
    printf("Goodbye\n");
  }
  return 0;
}
