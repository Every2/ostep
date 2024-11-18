#include <stdio.h>
#include <stdlib.h>

typedef struct vec {
	int* data;
	int capacity;
	int size;
} Vector;

Vector* init();
void push_back(Vector* vec, int value);
void remove_first(Vector *vec);
void free_vector(Vector *vec);
void print_vector(Vector *vec);
