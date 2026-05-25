#include "list.h"

#include <stdio.h>

int main(void) {
    int value = 0;

    DoublyLinkedList *list = list_create();
    if (list == NULL) {
        return 1;
    }

    list_push_back(list, 10);
    list_push_back(list, 20);
    list_push_front(list, 5);
    printf("Doubly linked list: ");
    list_print(list);

    list_remove(list, 10);
    printf("After removing 10: ");
    list_print(list);

    Stack *stack = list_create();
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_pop(stack, &value);
    printf("Stack pop: %d\n", value);

    Queue *queue = list_create();
    queue_enqueue(queue, 100);
    queue_enqueue(queue, 200);
    queue_dequeue(queue, &value);
    printf("Queue dequeue: %d\n", value);

    Deque *deque = list_create();
    deque_push_front(deque, 7);
    deque_push_back(deque, 9);
    deque_pop_back(deque, &value);
    printf("Deque pop back: %d\n", value);

    list_free(list);
    list_free(stack);
    list_free(queue);
    list_free(deque);

    return 0;
}
