#include "list.h"

#include <stdio.h>
#include <stdlib.h>

static Node *node_create(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

DoublyLinkedList *list_create(void) {
    DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_free(DoublyLinkedList *list) {
    if (list == NULL) {
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int list_push_front(DoublyLinkedList *list, int value) {
    if (list == NULL) {
        return 0;
    }

    Node *node = node_create(value);
    if (node == NULL) {
        return 0;
    }

    node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = node;
    } else {
        list->tail = node;
    }

    list->head = node;
    list->size++;
    return 1;
}

int list_push_back(DoublyLinkedList *list, int value) {
    if (list == NULL) {
        return 0;
    }

    Node *node = node_create(value);
    if (node == NULL) {
        return 0;
    }

    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }

    list->tail = node;
    list->size++;
    return 1;
}

int list_pop_front(DoublyLinkedList *list, int *value) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }

    Node *node = list->head;
    if (value != NULL) {
        *value = node->value;
    }

    list->head = node->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    free(node);
    list->size--;
    return 1;
}

int list_pop_back(DoublyLinkedList *list, int *value) {
    if (list == NULL || list->tail == NULL) {
        return 0;
    }

    Node *node = list->tail;
    if (value != NULL) {
        *value = node->value;
    }

    list->tail = node->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    free(node);
    list->size--;
    return 1;
}

Node *list_find(DoublyLinkedList *list, int value) {
    if (list == NULL) {
        return NULL;
    }

    Node *current = list->head;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int list_remove(DoublyLinkedList *list, int value) {
    Node *node = list_find(list, value);
    if (list == NULL || node == NULL) {
        return 0;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);
    list->size--;
    return 1;
}

void list_print(const DoublyLinkedList *list) {
    if (list == NULL) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (Node *current = list->head; current != NULL; current = current->next) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

int stack_push(Stack *stack, int value) {
    return list_push_back(stack, value);
}

int stack_pop(Stack *stack, int *value) {
    return list_pop_back(stack, value);
}

int queue_enqueue(Queue *queue, int value) {
    return list_push_back(queue, value);
}

int queue_dequeue(Queue *queue, int *value) {
    return list_pop_front(queue, value);
}

int deque_push_front(Deque *deque, int value) {
    return list_push_front(deque, value);
}

int deque_push_back(Deque *deque, int value) {
    return list_push_back(deque, value);
}

int deque_pop_front(Deque *deque, int *value) {
    return list_pop_front(deque, value);
}

int deque_pop_back(Deque *deque, int *value) {
    return list_pop_back(deque, value);
}
