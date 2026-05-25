#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t size;
} DoublyLinkedList;

typedef DoublyLinkedList Stack;
typedef DoublyLinkedList Queue;
typedef DoublyLinkedList Deque;

DoublyLinkedList *list_create(void);
void list_free(DoublyLinkedList *list);
int list_push_front(DoublyLinkedList *list, int value);
int list_push_back(DoublyLinkedList *list, int value);
int list_pop_front(DoublyLinkedList *list, int *value);
int list_pop_back(DoublyLinkedList *list, int *value);
Node *list_find(DoublyLinkedList *list, int value);
int list_remove(DoublyLinkedList *list, int value);
void list_print(const DoublyLinkedList *list);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);
int queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue, int *value);
int deque_push_front(Deque *deque, int value);
int deque_push_back(Deque *deque, int value);
int deque_pop_front(Deque *deque, int *value);
int deque_pop_back(Deque *deque, int *value);

#endif
