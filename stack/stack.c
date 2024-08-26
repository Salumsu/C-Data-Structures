#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack* create_stack(int size) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	int* arr = (int*)calloc(size, sizeof(int));

	stack->arr = arr;
	stack->size = size;
	stack->front = -1;

	return stack;
}

void push(Stack* stack, int val) {
	if (stack->front >= stack->size - 1) {
		int* new_arr = realloc(stack->arr, stack->size * 2 * sizeof(int));
		
		if (new_arr == NULL) {	
			errno = ENOMEM; 
			perror("Memory allocation failed");
			return;
		}

		stack->arr = new_arr;
		stack->size++;
	}

	stack->arr[++stack->front] = val;
}


int pop(Stack* stack) {
	if (stack->front == -1) {
		errno = ERANGE; 
		perror("Empty Queue");
		return -1;
	}

	return stack->arr[stack->front--];
}

void print_stack(Stack* stack) {
	for (int i = 0; i <= stack->front; i++) {
		printf("%d\n", stack->arr[i]);
	}
}