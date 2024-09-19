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
    wait(NULL);
    printf("Hello\n");
  }
  else {
    wait(NULL);
    printf("Goodbye\n");
  }
  return 0;
}
