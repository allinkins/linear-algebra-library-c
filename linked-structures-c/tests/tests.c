#include "list.h"

#include <stdio.h>

static int test_list_push_pop(void) {
    int value = 0;
    DoublyLinkedList *list = list_create();
    if (list == NULL) {
        return 0;
    }

    list_push_back(list, 2);
    list_push_front(list, 1);
    list_push_back(list, 3);

    int ok = list->size == 3 &&
             list_pop_front(list, &value) && value == 1 &&
             list_pop_back(list, &value) && value == 3 &&
             list_pop_back(list, &value) && value == 2 &&
             !list_pop_back(list, &value);

    list_free(list);
    return ok;
}

static int test_list_find_remove(void) {
    DoublyLinkedList *list = list_create();
    if (list == NULL) {
        return 0;
    }

    list_push_back(list, 4);
    list_push_back(list, 5);
    list_push_back(list, 6);

    int ok = list_find(list, 5) != NULL &&
             list_remove(list, 5) &&
             list_find(list, 5) == NULL &&
             list->size == 2 &&
             !list_remove(list, 100);

    list_free(list);
    return ok;
}

static int test_stack(void) {
    int value = 0;
    Stack *stack = list_create();
    if (stack == NULL) {
        return 0;
    }

    stack_push(stack, 10);
    stack_push(stack, 20);

    int ok = stack_pop(stack, &value) && value == 20 &&
             stack_pop(stack, &value) && value == 10 &&
             !stack_pop(stack, &value);

    list_free(stack);
    return ok;
}

static int test_queue(void) {
    int value = 0;
    Queue *queue = list_create();
    if (queue == NULL) {
        return 0;
    }

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);

    int ok = queue_dequeue(queue, &value) && value == 10 &&
             queue_dequeue(queue, &value) && value == 20 &&
             !queue_dequeue(queue, &value);

    list_free(queue);
    return ok;
}

static int test_deque(void) {
    int value = 0;
    Deque *deque = list_create();
    if (deque == NULL) {
        return 0;
    }

    deque_push_front(deque, 2);
    deque_push_front(deque, 1);
    deque_push_back(deque, 3);

    int ok = deque_pop_front(deque, &value) && value == 1 &&
             deque_pop_back(deque, &value) && value == 3 &&
             deque_pop_front(deque, &value) && value == 2 &&
             !deque_pop_front(deque, &value);

    list_free(deque);
    return ok;
}

static void run_test(const char *name, int (*test)(void), int *failed) {
    if (test()) {
        printf("%s: PASSED\n", name);
    } else {
        printf("%s: FAILED\n", name);
        (*failed)++;
    }
}

int main(void) {
    int failed = 0;

    run_test("test_list_push_pop", test_list_push_pop, &failed);
    run_test("test_list_find_remove", test_list_find_remove, &failed);
    run_test("test_stack", test_stack, &failed);
    run_test("test_queue", test_queue, &failed);
    run_test("test_deque", test_deque, &failed);

    return failed == 0 ? 0 : 1;
}
