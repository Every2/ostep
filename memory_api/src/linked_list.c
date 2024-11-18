#include "../include/linked_list.h"

void print_list(Node_t *head) {
	Node_t *current = head;

	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

void append(Node_t **head, int value) {
    Node_t *new_node;
	new_node = (Node_t *) malloc(sizeof(Node_t));
	new_node->data = value;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else {
		Node_t *last_node = *head;

		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}
}

int delete_head(Node_t **head) {
	Node_t *temp;
	temp = *head;
	int value = temp->data;
	*head = (*head)->next;
	free(temp);

	return value;
}

void free_list(Node_t *list) {
	if (list == NULL)
		return;

	free_list(list->next);
	free(list);
}

