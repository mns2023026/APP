#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Stack_Node {
    int val;
    struct Stack_Node *next;
};

struct Stack {
    int Ele_in_queue;
    struct Stack_Node *head;
    struct Stack_Node *tail;
};

struct Stack *init_Stack();
int isNull(struct Stack *q);
void Push(struct Stack *q, int n);
int Pop(struct Stack *q);
int Peek(struct Stack *q);
void print_Stack(struct Stack *q);

#endif /* STACK_H */
