#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
int count_nodes(Node* head);
Node* find_by_value(Node* curr, int val);
Node* get_node_at(Node* curr, int index);
Node* find_middle(Node* curr);
Node* clone_list(Node* head);
void merge_lists(Node** list1, Node** list2);
void reverse_list(Node** head);

#endif