#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void test_stack_operations() {
    Stack* stack = create_stack(5);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("Stack contents:\n");
    print_stack(stack);

    printf("Popped: %d\n", pop(stack));

    printf("Stack contents after pop:\n");
    print_stack(stack);

    push(stack, 6);
    printf("Stack contents after push 6:\n");
    print_stack(stack);

    printf("Popped: %d\n", pop(stack));
    printf("Stack contents after pop:\n");
    print_stack(stack);


    free(stack->arr);
    free(stack);
}

int main() {
    test_stack_operations();
    return 0;
}
