#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue {
	int* arr;
	int front;
	int tail;
	int size;
} Queue;

Queue* create_queue(int size);
void enqueue(Queue* queue, int val);
void display_queue(Queue* queue);
int dequeue(Queue* queue);
bool is_empty(Queue* queue);

#endif