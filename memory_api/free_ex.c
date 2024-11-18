#include <stdio.h>
#include <stdlib.h>

int main() {
	int *data = malloc(100 * sizeof (*data));
	data[100] = 0;
	free(data + 50);
	printf("%d\n", data[50]);
}
