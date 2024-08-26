#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void test_queue_operations() {
    printf("Test: Queue Operations\n");

    Queue* queue = create_queue(5);

    printf("Enqueue 1, 2, 3, 4, 5\n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Queue contents:\n");
    display_queue(queue);

    printf("Dequeue operation\n");
    printf("Dequeued: %d\n", dequeue(queue));

    printf("Queue contents after dequeue:\n");
    display_queue(queue);

    printf("Enqueue 6\n");
    enqueue(queue, 6);
    printf("Queue contents after enqueue 6:\n");
    display_queue(queue);

    printf("Dequeue operation\n");
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue contents after dequeue:\n");
    display_queue(queue);

    free(queue->arr);
    free(queue);
}

int main() {
    test_queue_operations();
    return 0;
}
