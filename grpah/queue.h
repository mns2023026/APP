#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int val;
    struct Node *next;
};

struct Queue {
    int number_ele;
    int Ele_in_queue;
    struct Node *head;
    struct Node *tail;
};

struct Queue *initQueue(int n);
int isNull(struct Queue *q);
int isFull(struct Queue *q);
void Enqueue(struct Queue *q, int n);
int Dequeue(struct Queue *q);
int Peek(struct Queue *q);
void print_Queue(struct Queue *q);

#endif // QUEUE_H
