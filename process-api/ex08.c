#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int first_c;
  int second_c;
  char buffer[100];
  int pipefd[2];

  if (pipe(pipefd) == -1) {
    fprintf(stderr, "pipe error\n");
    exit(1);
  }

  //Create the child process
  if (!(first_c = fork())) {
    //close the unused
    close(pipefd[0]);
    //redirect to stdout
    if (pipefd[1] != STDOUT_FILENO) {
      if (dup2(pipefd[1], STDOUT_FILENO) != STDOUT_FILENO) {
        fprintf(stderr, "dup2 error\n");
        exit(1);
      }
      //close
      close(pipefd[1]);
    }
    //send the message to stdout
    printf("hello");
  } else {
    //create the second child process
    if (!(second_c = fork())) {
      //close the unused
      close(pipefd[1]);
      //redirect to stdin
      if (pipefd[0] != STDIN_FILENO) {
        if (dup2(pipefd[0], STDIN_FILENO) != STDIN_FILENO) {
          fprintf(stderr, "dup2 error\n");
          exit(1);
        }
        close(pipefd[0]);
      }

      //read what is income
      read(STDIN_FILENO, buffer, 100);
      //read and print
      printf("from inside: %s\n", buffer);
    } else {
      //wait calls
      if (waitpid(first_c, NULL, 0) == -1) {
        fprintf(stderr, "waitpid  error\n");
        exit(1);
      }
      if (waitpid(second_c, NULL, 0) == -1) {
        fprintf(stderr, "waitpid  error\n");
        exit(1);
      }
    }
  }

  return 0;
}
