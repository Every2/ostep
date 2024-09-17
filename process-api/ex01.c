#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
  int external_var  = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  }
  else if (rc == 0)
    printf("inside fork %d\n", ++external_var);
  else
    printf("in main process %d\n", --external_var);
}
