#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linked-list.h"

Node* create_node (int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		return NULL;
	}

	node->val = val;
	node->next = NULL;
	return node;
}

void print_nodes (Node* curr) {
	if (curr == NULL) {
		printf("Empty\n");
		return;
	}
	while (curr != NULL) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}
}

void append_val(Node** linked_list, int val) {
	Node* curr = (Node*)*linked_list; // HEAD
	Node* new_node = create_node(val);
	if (curr == NULL) {
		*linked_list = new_node;
		return;
	}

	while (curr->next != NULL) {
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
	if (curr == NULL) {
		*linked_list = new_node;
		return;
	}

	int current_index = 0;
	Node* prev = NULL;
	while (current_index < index && curr != NULL) {
		prev = curr;
		curr =  curr->next;
		current_index++;
	}

	if (current_index < index) {
		errno = ERANGE;
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
	}

	if (prev == NULL) {
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
		return;
	}
	Node* curr = (Node*)*linked_list; // HEAD

	if (curr == NULL) return;

	Node* prev = NULL;
	int current_index = 0;

	while (current_index < index && curr != NULL) {
		prev = curr;
		curr = curr->next;
		current_index++;
	}

	if (current_index < index) {
		errno = ERANGE;
        perror("Index out of bounds");
		return;
	}

	if (curr != NULL) {
		if (prev == NULL) {
			*linked_list = curr->next;
		} else {
			prev->next = curr->next;
			free(curr);
		}
	} 
}

Node* pop (Node** linked_list) {
	Node* curr = (Node*)*linked_list; // HEAD
	if (curr == NULL) return NULL;

	Node* prev = NULL;
	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL) {
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
		while (curr->next != NULL) {
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
		while (curr->next != NULL) {
			if (curr->val > curr->next->val) {
				isSorted = false;
				Node* next = curr->next;
				curr->next = next->next;
				next->next = curr;
				if (prev == NULL) {
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


int count_nodes(Node* head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}

	return count;
}

Node* find_by_value(Node* curr, int val) {
	while (curr != NULL) {
		if (curr->val == val) {
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
} 

Node* get_node_at (Node* curr, int index) {
	if (index < 0) {
		return NULL;
	}

	int current_index = 0;
	while (current_index < index && curr != NULL) {
		curr = curr->next;
		current_index++;
	}
	
	return curr;
}

Node* find_middle(Node* curr) {
	if (curr == NULL) {
		return NULL;
	}
	Node* fast = curr;
	while (fast != NULL && fast->next != NULL && fast->next->next) {
		curr = curr->next;
		fast = fast->next->next;
	}

	return curr;
}

Node* clone_list(Node* head) {
	if (head == NULL) return NULL;
	Node* new_list = create_node(head->val);
	Node* curr = new_list;
	head = head->next;

	while(head != NULL) {
		Node* new_node = create_node(head->val);
		curr->next = new_node;
		curr = curr->next;
		head = head->next;
	}

	return new_list;
}

void merge_lists(Node** list1, Node** list2) {
	Node* new_list = *list1;
	if (new_list == NULL) {
		*list1 = *list2;
		return;
	}

	while (new_list->next != NULL) {
		new_list = new_list->next;
	}
	new_list->next = *list2;
}

void reverse_list(Node** linked_list) {
	Node* curr = (Node*)*linked_list;
	if (curr == NULL) return;

	Node* prev = curr;
	curr = curr->next;
	prev->next = NULL;

	while (curr->next != NULL) {
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	curr->next = prev;

	*linked_list = curr;
}