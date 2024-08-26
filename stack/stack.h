#ifndef STACK_H
#define STACK_H

typedef struct Stack {
	int* arr;
	int front;
	int size;
} Stack;

Stack* create_stack(int size);
void push(Stack* stack, int val);
int pop(Stack* stack);
void print_stack(Stack* stack);

#endif