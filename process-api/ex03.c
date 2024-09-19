#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  //É possiível usar kill e redirecionar para SIGCOUNT, assim faz o child process executar primeiro
  // Mas preferi usar a abordagem do pipe bloquear o parent para rodar o child primeiro e depois o parent.
  int pipef[2];
  if (pipe(pipef) == -1) {
    fprintf(stderr, "pipe failed\n");
    exit(EXIT_FAILURE);
  }

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    printf("Hello\n");
    close(pipef[0]);
    write(pipef[1], "c", 1);
    close(pipef[1]);
  } else {
    close(pipef[1]);
    char c;
    read(pipef[0], &c, 1);
    close(pipef[0]);
    printf("Goodbye\n");
  }

  return 0;
}
