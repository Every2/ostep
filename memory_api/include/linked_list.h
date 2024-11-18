#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node_t;

void print_list(Node_t *head);
void append(Node_t **head, int value);
int delete_head(Node_t **head);
void free_list(Node_t *head);
