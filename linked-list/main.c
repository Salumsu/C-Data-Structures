#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int val;
	struct Node* next;
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


int main() {
	Node* head = create_node(5);

	append_val(&head, 1);
	append_val(&head, 3);
	append_val(&head, 7);
	append_val(&head, 2);

	print_nodes(head);
	sort_nodes(&head);
	printf("===========\n");
	
	print_nodes(head);

	return 0;
}


Node* create_node (int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (is_empty(node)) {
		return NULL;
	}

	node->val = val;
	node->next = NULL;
	return node;
}

void print_nodes (Node* curr) {
	if (is_empty(curr)) {
		printf("Empty\n");
		return;
	}
	while (!is_empty(curr)) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}
}

void append_val(Node** linked_list, int val) {
	Node* curr = (Node*)*linked_list; // HEAD
	Node* new_node = create_node(val);
	if (is_empty(curr)) {
		*linked_list = new_node;
		return;
	}

	while (!is_empty(curr->next)) {
		curr = curr->next;
	}

	curr->next = new_node;
}

void prepend_val(Node** linked_list, int val) {
	Node* new_head = create_node(val);
	new_head->next = ((Node*)*linked_list);
	*linked_list = new_head;
}

void insert_at(Node** linked_list, int index, int val) {
	if (index < 0) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}
	Node* new_node = create_node(val);
	Node* curr = (Node*)*linked_list; // HEAD
	if (is_empty(curr)) {
		*linked_list = new_node;
		return;
	}

	int current_index = 0;
	Node* prev = NULL;
	while (current_index < index && !is_empty(curr)) {
		prev = curr;
		curr =  curr->next;
		current_index++;
	}

	if (current_index < index) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	if (is_empty(prev)) {
		new_node->next = (Node*)*linked_list;
		*linked_list = new_node;
	} else {
		new_node->next = curr;
		prev->next = new_node;
	}
}

void remove_at(Node** linked_list, int index) {
	if (index < 0) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}
	Node* curr = (Node*)*linked_list; // HEAD

	if (is_empty(curr)) return;

	Node* prev = NULL;
	int current_index = 0;

	while (current_index < index && !is_empty(curr)) {
		prev = curr;
		curr = curr->next;
		current_index++;
	}

	if (current_index < index) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	if (!is_empty(curr)) {
		if (is_empty(prev)) {
			*linked_list = curr->next;
		} else {
			prev->next = curr->next;
			free(curr);
		}
	} 
}

Node* pop (Node** linked_list) {
	Node* curr = (Node*)*linked_list; // HEAD
	if (is_empty(curr)) return NULL;

	Node* prev = NULL;
	while (!is_empty(curr->next)) {
		prev = curr;
		curr = curr->next;
	}

	if (is_empty(prev)) {
		*linked_list = NULL;
	} else {
		prev->next = NULL;
	}
	return curr;
}

void sort_vals (Node* head) {
	bool is_sorted = false;
	while (!is_sorted) {
		Node* curr = head;
		is_sorted = true;
		while (!is_empty(curr->next)) {
			if (curr->val > curr->next->val) {
				is_sorted = false;
				int temp = curr->val;
				curr->val = curr->next->val;
				curr->next->val = temp;
			}
			curr = curr->next;
		}
	}
}

void sort_nodes (Node** linked_list) {
	bool isSorted = false;
	while (!isSorted) {
		Node* curr = (Node*)*linked_list; // HEAD
		Node* prev = NULL;
		isSorted = true;
		while (!is_empty(curr->next)) {
			if (curr->val > curr->next->val) {
				isSorted = false;
				Node* next = curr->next;
				curr->next = next->next;
				next->next = curr;
				if (is_empty(prev)) {
					*linked_list = next;
				} else {
					prev->next = next;
				}
				prev = next;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

bool is_empty (Node* head) {
	return head == NULL;
}
