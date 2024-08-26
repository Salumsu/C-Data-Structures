#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

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

int main() {
	Queue* queue = create_queue(3);
	enqueue(queue, 4);
	enqueue(queue, 3);
	enqueue(queue, 5);

	while (!is_empty(queue)) {
		printf("%d\n", dequeue(queue));
	}

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);


	while (!is_empty(queue)) {
		printf("%d\n", dequeue(queue));
	}
	

	return 0;
}

Queue* create_queue(int size) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	int* arr = (int*)malloc(sizeof(int) * size);

	queue->arr = arr;
	queue->size = size;
	queue->front = -1;
	queue->tail = -1;

	return queue;
}

void enqueue(Queue* queue, int val) {
	if (is_empty(queue)) queue->front = 0;

	if (queue->tail == queue->size - 1) {
		int* new_arr = realloc(queue->arr, queue->size * 2 * sizeof(int));
		if (new_arr == NULL) {
			errno = ENOMEM; 
			perror("Memory allocation failed");
			exit(EXIT_FAILURE); 
		}

		queue->arr = new_arr;
		queue->size *= 2;
	}

	queue->arr[++queue->tail] = val;
}

void display_queue(Queue* queue) {
	for (int i = queue->front; i <= queue->tail; i++) {
		printf("%d: %d\n", i - queue->front, queue->arr[i]);
	}
}


int dequeue(Queue* queue) {
	if (is_empty(queue)) {
		errno = ERANGE; 
		perror("Empty Queue");
		exit(EXIT_FAILURE); 
	}

	int val = queue->arr[queue->front++];

	if (queue->front >= queue->size/2) {
		int current_size = (queue->tail - queue->front) + 1;
		for (int i = 0; i < current_size; i++) {
			queue->arr[i] = queue->arr[queue->front + i];
		}
		queue->tail -= queue->front;
		queue->front = 0;
	}

	if (queue->tail < queue->front) {
		queue->tail = -1;
		queue->front = -1;
	}

	return val;
}


bool is_empty(Queue* queue) {
	return queue->front == -1 && queue->tail == -1 || queue->tail < queue->front;
}