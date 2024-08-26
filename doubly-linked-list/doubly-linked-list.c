#include <stdlib.h>
#include <stdio.h>
#include "doubly-linked-list.h"

Node* create_node (int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void print_nodes(Node* curr) {
	if (curr == NULL) return;
	while (curr->next != NULL) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}

	printf("%d <>\n", curr->val);
	curr = curr->prev;

	while (curr != NULL) {
		printf("%d\n", curr->val);
		curr = curr->prev;
	}
}

void append_val (Node** linked_list, int val) {
	Node* new_node = create_node(val);
	Node* curr = (Node*)*linked_list;
	if (curr == NULL) {
		*linked_list = new_node;
		return;
	}

	while (curr->next != NULL) {
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
	if (prev_head != NULL) {
		prev_head->prev = new_head;
	}
}

void insert_at (Node** linked_list, int index, int val) {
	if (index < 0) {
		errno = ERANGE;
        perror("Index out of bounds");
        return;
	}
	Node* new_node = create_node(val);
	Node* curr = (Node*)*linked_list;
	if (curr == NULL) {
		*linked_list = new_node;
		return;
	}

	int current_index = 0;
	while (current_index < index && curr != NULL) {
		curr = curr->next;
		current_index++;
	}

	if (curr == NULL) {
		errno = ERANGE;
        perror("Index out of bounds");
		return;
	}

	Node* prev = curr->prev;
	if (prev == NULL) {
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
        return;
	}

	Node* curr = (Node*)*linked_list;
	if (curr == NULL) return;

	int current_index = 0;
	while (current_index < index && curr != NULL) {
		curr = curr->next;
		current_index++;
	}

	if (curr == NULL) {
		errno = ERANGE;
        perror("Index out of bounds");
        return;
	}

	Node* prev = curr->prev;

	if (prev == NULL) {
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
	if (curr == NULL) return NULL;
	
	while (curr->next != NULL) {
		curr = curr->next;
	}

	Node* prev = curr->prev;
	if (prev == NULL) {
		*linked_list = NULL;
	} else {
		prev->next = curr->next;
		if (curr->next != NULL) {
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
		while (curr->next != NULL) {
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
		while (curr->next != NULL) {
			if (curr->val > curr->next->val) {
				Node* next = curr->next;
				curr->next = next->next;
				if (next->next != NULL) {
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
		new_node->prev = curr;
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
	
	Node* next = (Node*)*list2;
	if (*list2 != NULL) {
		next->prev = new_list;
	}

	new_list->next = next;
}

void reverse_list(Node** linked_list) {
    Node* curr = (Node*)*linked_list;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;

        prev = curr;
        curr = next;
    }

    *linked_list = prev;
}
