#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node* next;
	struct Node* prev;
} Node;

Node* create_node (int val);
void print_nodes (Node* curr);
void append_val(Node** linked_list, int val);
void prepend_val(Node** linked_list, int val);
void insert_at(Node** linked_list, int index, int val);
void remove_at(Node** linked_list, int index);
Node* pop (Node** linked_list);
void sort_vals (Node* curr);
void sort_nodes (Node** linked_list);
bool is_empty (Node* head);

int main () {
	Node* head = create_node(5);
	append_val(&head, 4);
	append_val(&head, 7);
	append_val(&head, 1);
	insert_at(&head, 0, 0);
	print_nodes(head);
	printf("============\n");
	sort_nodes(&head);
	print_nodes(head);


	return 0;
}

Node* create_node (int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void print_nodes(Node* curr) {
	if (is_empty(curr)) return;
	while (!is_empty(curr->next)) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}

	printf("%d <>\n", curr->val);
	curr = curr->prev;

	while (!is_empty(curr)) {
		printf("%d\n", curr->val);
		curr = curr->prev;
	}
}

void append_val (Node** linked_list, int val) {
	Node* new_node = create_node(val);
	Node* curr = (Node*)*linked_list;
	if (is_empty(curr)) {
		*linked_list = new_node;
		return;
	}

	while (!is_empty(curr->next)) {
		curr = curr->next;
	}

	curr->next = new_node;
	new_node->prev = curr;
}

void prepend_val (Node** linked_list, int val) {
	Node* new_head = create_node(val);
	Node* prev_head = (Node*)*linked_list; 
	new_head->next = prev_head;
	*linked_list = new_head;
	if (!is_empty(prev_head)) {
		prev_head->prev = new_head;
	}
}

void insert_at (Node** linked_list, int index, int val) {
	if (index < 0) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}
	Node* new_node = create_node(val);
	Node* curr = (Node*)*linked_list;
	if (is_empty(curr)) {
		*linked_list = new_node;
		return;
	}

	int current_index = 0;
	while (current_index < index && !is_empty(curr)) {
		curr = curr->next;
		current_index++;
	}

	if (is_empty(curr)) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	Node* prev = curr->prev;
	if (is_empty(prev)) {
		curr->prev = new_node;
		new_node->next = curr;
		*linked_list = new_node;
	} else {
		prev->next = new_node;
		new_node->prev = prev;
		new_node->next = curr;
		curr->prev = new_node;
	}
}

void remove_at (Node** linked_list, int index) {
	if (index < 0) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	Node* curr = (Node*)*linked_list;
	if (is_empty(curr)) return;

	int current_index = 0;
	while (current_index < index && !is_empty(curr)) {
		curr = curr->next;
		current_index++;
	}

	if (is_empty(curr)) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	Node* prev = curr->prev;

	if (is_empty(prev)) {
		*linked_list = curr->next;
	} else {
		prev->next = curr->next;
	} 

	if (curr->next != NULL) {
		curr->next->prev = prev;
	}
	free(curr);
}

Node* pop (Node** linked_list) {
	Node* curr = (Node*)*linked_list;
	if (is_empty(curr)) return NULL;
	
	while (!is_empty(curr->next)) {
		curr = curr->next;
	}

	Node* prev = curr->prev;
	if (is_empty(prev)) {
		*linked_list = NULL;
	} else {
		prev->next = curr->next;
		if (!is_empty(curr->next)) {
			curr->next->prev = prev;
		}
	}
	curr->prev = NULL;
	return curr;
}

void sort_vals(Node* head) {
	bool is_sorted = false;
	while (!is_sorted) {
		is_sorted = true;
		Node* curr = head;
		while (!is_empty(curr->next)) {
			if (curr->val > curr->next->val) {
				int temp = curr->val;
				curr->val = curr->next->val;
				curr->next->val = temp;
			} 	
			curr = curr->next;
		}
	}
}

void sort_nodes(Node** linked_list) {
	bool is_sorted = false;
	while (!is_sorted) {
		is_sorted = true;
		Node* curr = (Node*)*linked_list;
		Node* prev = NULL;
		while (!is_empty(curr->next)) {
			if (curr->val > curr->next->val) {
				Node* next = curr->next;
				curr->next = next->next;
				if (!is_empty(next->next)) {
					next->next->prev = curr;
				}

				next->next = curr;
				curr->prev = next;

				if (prev == NULL) {
					next->prev = NULL;
					*linked_list = next;
				} else {
					prev->next = next;
					next->prev = prev;
				}
				prev = next;
				is_sorted = false;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

bool is_empty(Node* head) {
	return head == NULL;
}