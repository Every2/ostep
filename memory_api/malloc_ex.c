#include <stdlib.h>

int main() {
	int *data = malloc(100 * sizeof (*data));
	data[100] = 0;
}
