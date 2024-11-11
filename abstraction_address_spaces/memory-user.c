#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char *p;
	char *p2;
	errno = 0;

	int n;
	int n2;

	if (argc < 2) {
		printf("Insert the amount of memory in megabytes and the time (in seconds) that program should run\n");
		exit(1);
	}

	int first_arg_to_int = strtol(argv[1], &p, 10);
	int second_arg_to_int = strtol(argv[2], &p2, 10);
	if (errno != 0 || *p != '\0' || first_arg_to_int > INT_MAX || first_arg_to_int < INT_MIN) {
		printf("can't convert argv[1] to int");
		exit(1);
	} else {
		n = first_arg_to_int;
	}

	if (errno != 0 || *p2 != '\0' || second_arg_to_int > INT_MAX || second_arg_to_int < INT_MIN) {
		printf("can't convert argv[2] to int");
		exit(1);
	} else {
		n2 = second_arg_to_int;
	}

	int buffer[n];

	for (int i = 0; i <= n ; i++) {
		buffer[i] = i;
		sleep(n2);
		printf("%d\n", i);
	}

	return 0;
}
