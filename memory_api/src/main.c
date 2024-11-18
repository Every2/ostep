#include "../include/linked_list.h"
#include "../include/vector.h"

int main() {
	Node_t *foo = NULL;
	Vector* vec = init();
	
	for (int i = 0; i < 10; i++) 
	    append(&foo, i);

	for (int i = 0; i < 7; i++)
		push_back(vec, i);

	print_list(foo);
	delete_head(&foo);
	printf("-------------------------\n");
	print_list(foo);
	printf("--------------------------\n");
	print_vector(vec);
	printf("--------------------\n");
	remove_first(vec);
	print_vector(vec);
	free_list(foo);
	free_vector(vec);
}
