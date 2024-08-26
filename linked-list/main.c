#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked-list.h"

void test_create_node();
void test_print_nodes();
void test_append_val();
void test_prepend_val();
void test_insert_at();
void test_remove_at();
void test_pop();
void test_sort_vals();
void test_sort_nodes();
void test_count_nodes();
void test_find_by_value();
void test_get_node_at();
void test_find_middle();
void test_find_middle_even();
void test_clone_list();
void test_merge_lists();
void test_reverse_list();

int main() {
    // Run all tests
    test_create_node();
    test_print_nodes();
    test_append_val();
    test_prepend_val();
    test_insert_at();
    test_remove_at();
    test_pop();
    test_sort_vals();
    test_sort_nodes();
    test_count_nodes();
    test_find_by_value();
    test_get_node_at();
    test_find_middle();
    test_find_middle_even();
    test_clone_list();
    test_merge_lists();
    test_reverse_list();

    return 0;
}

void test_create_node() {
    Node* node = create_node(10);
    printf("\n================\nTest: Create Node\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", node->val);
    free(node);
}

void test_print_nodes() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    printf("\n================\nTest: Print Nodes\n");
	printf("Should print: 1 2 3\n");
    print_nodes(head); 
}

void test_append_val() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    printf("\n================\nTest: Append Value\n");
	printf("Should print: 1 2 3\n");
    print_nodes(head);
}

void test_prepend_val() {
    Node* head = create_node(1);
    prepend_val(&head, 0);
    prepend_val(&head, -1);
    printf("\n================\nTest: Prepend Value\n");
	printf("Should print: -1 0 1\n");
    print_nodes(head);
}

void test_insert_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 4);
    insert_at(&head, 2, 3);
    printf("\n================\nTest: Insert At\n");
	printf("Should print: 1 2 3 4\n");
    print_nodes(head); 
}

void test_remove_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    remove_at(&head, 1);
    printf("\n================\nTest: Remove At\n");
	printf("Should print: 1 3\n");
    print_nodes(head); 
}

void test_pop() {
    Node* head = create_node(1);
    append_val(&head, 2);
    Node* popped = pop(&head);
    printf("\n================\nTest: Pop\n");
    printf("Expected: 2\n");
    printf("Actual: %d\n", popped ? popped->val : -1);
	printf("Should print: 1\n");

    print_nodes(head);
}

void test_sort_vals() {
    Node* head = create_node(3);
    append_val(&head, 1);
    append_val(&head, 2);
    sort_vals(head);
    printf("\n================\nTest: Sort Values\n");
	printf("Should print: 1 2 3\n");
    print_nodes(head); 
}

void test_sort_nodes() {
    Node* head = create_node(3);
    append_val(&head, 1);
    append_val(&head, 2);
    sort_nodes(&head);
    printf("\n================\nTest: Sort Nodes\n");
	printf("Should print: 1 2 3\n");
    print_nodes(head); 
}

void test_count_nodes() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    printf("\n================\nTest: Count Nodes\n");
    printf("Expected: 3\n");
    printf("Actual: %d\n", count_nodes(head));
}

void test_find_by_value() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    Node* found = find_by_value(head, 2);
    printf("\n================\nTest: Find By Value\n");
    printf("Expected: 2\n");
    printf("Actual: %d\n", found ? found->val : -1);
}

void test_get_node_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    Node* node = get_node_at(head, 1);
    printf("\n================\nTest: Get Node At\n");
    printf("Expected: 2\n");
    printf("Actual: %d\n", node ? node->val : -1);
}

void test_find_middle() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    append_val(&head, 4);
    append_val(&head, 5);
    Node* middle = find_middle(head);
    printf("\n================\nTest: Find Middle\n");
    printf("Expected: 3\n");
    printf("Actual: %d\n", middle ? middle->val : -1);
}

void test_find_middle_even() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    append_val(&head, 4);
    Node* middle = find_middle(head);
    printf("\n================\nTest: Find Middle (Even)\n");
    printf("Expected: 2\n");
    printf("Actual: %d\n", middle ? middle->val : -1);
}

void test_clone_list() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    Node* cloned = clone_list(head);
    printf("\n================\nTest: Clone List\n");
    print_nodes(cloned); // Should print: 1 2 3
}

void test_merge_lists() {
    Node* list1 = create_node(1);
    append_val(&list1, 2);
    Node* list2 = create_node(3);
    append_val(&list2, 4);
    merge_lists(&list1, &list2);
    printf("\n================\nTest: Merge Lists\n");
	printf("Should print: 1 2 3 4\n");
    print_nodes(list1);
}

void test_reverse_list() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    reverse_list(&head);
    printf("\n================\nTest: Reverse List\n");
	printf("Should print: 3 2 1\n");
    print_nodes(head); 
}
