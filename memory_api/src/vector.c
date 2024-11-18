#include "../include/vector.h"

Vector* init() {
	Vector* v = (Vector*)malloc(sizeof(Vector));
	v->data = (int*)malloc(sizeof(Vector));
	v->size = 0;
	v->capacity = 1;

	return v;
}

void push_back(Vector* vec, int value) {
    if (vec->size >= vec->capacity) {
		vec->capacity *= 2;
		int *new_data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
		vec->data = new_data;
	}

	vec->data[vec->size] = value;
	vec->size++;
}

void remove_first(Vector *vec) {
	if (vec->size == 0)
		return;

	for (int i = 0; i < vec->size; i++)
		vec->data[i - 1] = vec->data[i];

	vec->size--;
}

void print_vector(Vector *vec) {
	for (int i = 0; i < vec->size; i++)
		printf("%d\n", vec->data[i]);
}

void free_vector(Vector *vec) {
	free(vec->data);
	free(vec);
}
