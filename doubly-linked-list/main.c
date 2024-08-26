#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

// Function Definitions
void test_create_node();
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
void test_clone_list();
void test_merge_lists();
void test_reverse_list();

// Main function
int main() {
    test_create_node();
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
    test_clone_list();
    test_merge_lists();
    test_reverse_list();

    return 0;
}

// Function Implementations
void test_create_node() {
    Node* node = create_node(10);
    printf("\n===============\nTest create_node: Expected 10, got %d\n", node->val);
    free(node);
}

void test_append_val() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    printf("\n===============\nTest append_val: Expected (1, 2, 3), got\n");
    print_nodes(head);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_prepend_val() {
    Node* head = create_node(1);
    prepend_val(&head, 0);
    printf("\n===============\nTest prepend_val: Expected (0, 1), got\n");
    print_nodes(head);
    free(head->next);
    free(head);
}

void test_insert_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    insert_at(&head, 1, 3);
    printf("\n===============\nTest insert_at: Expected (1, 3, 2), got\n");
    print_nodes(head);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_remove_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    remove_at(&head, 1);
    printf("\n===============\nTest remove_at: Expected (1, 3), got\n");
    print_nodes(head);
    free(head->next);
    free(head);
}

void test_pop() {
    Node* head = create_node(1);
    append_val(&head, 2);
    Node* popped = pop(&head);
    printf("\n===============\nTest pop: Expected 2, got %d\n", popped->val);
    printf("Test pop: Expected (1), got \n");
    print_nodes(head);
    free(popped);
    free(head);
}

void test_sort_vals() {
    Node* head = create_node(3);
    append_val(&head, 1);
    append_val(&head, 2);
    sort_vals(head);
    printf("\n===============\nTest sort_vals: Expected (1, 2, 3), got\n");
    print_nodes(head);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_sort_nodes() {
    Node* head = create_node(3);
    append_val(&head, 1);
    append_val(&head, 2);
    sort_nodes(&head);
    printf("\n===============\nTest sort_nodes: Expected (1, 2, 3), got\n");
    print_nodes(head);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_count_nodes() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    int count = count_nodes(head);
    printf("\n===============\nTest count_nodes: Expected 3, got %d\n", count);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_find_by_value() {
    Node* head = create_node(1);
    append_val(&head, 2);
    Node* found = find_by_value(head, 2);
    printf("\n===============\nTest find_by_value: Expected 2, got %d\n", found->val);
    free(head->next);
    free(head);
}

void test_get_node_at() {
    Node* head = create_node(1);
    append_val(&head, 2);
    Node* node = get_node_at(head, 1);
    printf("\n===============\nTest get_node_at: Expected 2, got %d\n", node->val);
    free(head->next);
    free(head);
}

void test_find_middle() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    Node* middle = find_middle(head);
    printf("\n===============\nTest find_middle: Expected 2, got %d\n", middle->val);
    free(head->next->next);
    free(head->next);
    free(head);
}

void test_clone_list() {
    Node* head = create_node(1);
    append_val(&head, 2);
    Node* clone = clone_list(head);
    printf("\n===============\nTest clone_list: Expected (1, 2), got\n");
    print_nodes(clone);
    free(clone->next);
    free(clone);
    free(head->next);
    free(head);
}

void test_merge_lists() {
    Node* list1 = create_node(1);
    append_val(&list1, 2);
    Node* list2 = create_node(3);
    merge_lists(&list1, &list2);
    printf("\n===============\nTest merge_lists: Expected (1, 2, 3), got\n");
    print_nodes(list1);
    free(list1->next->next);
    free(list1->next);
    free(list1);
}

void test_reverse_list() {
    Node* head = create_node(1);
    append_val(&head, 2);
    append_val(&head, 3);
    reverse_list(&head);
    printf("\n===============\nTest reverse_list: Expected (3, 2, 1), got\n");
    print_nodes(head);
    free(head->next->next);
    free(head->next);
    free(head);
}
