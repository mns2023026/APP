#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct queue_node {
    int val;
    struct queue_node *next;
};

struct queue {
    int number_ele;
    int ele_in_queue;
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue *init_queue(int n) {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));

    if (q == NULL) {
        perror("Can't acquire memory");
        exit(1);
    }

    q->ele_in_queue = 0;
    q->number_ele = n;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

int is_null(struct queue *q) {
    return q->head == NULL;
}

int is_full(struct queue *q) {
    return q->number_ele == q->ele_in_queue;
}

void enqueue(struct queue *q, int n) {
    if (is_full(q)) {
        perror("Queue Full\n");
        return;
    }

    struct queue_node *cn = (struct queue_node *)malloc(sizeof(struct queue_node));

    if (cn == NULL) {
        perror("Can't acquire memory\n");
        return;
    }

    cn->val = n;
    q->ele_in_queue++;

    if (q->head == NULL) {
        q->head = cn;
        q->tail = cn;
        return;
    }

    q->tail->next = cn;
    q->tail = cn;
}

int dequeue(struct queue *q) {
    int tmp_val;

    if (is_null(q)) {
        perror("Queue Empty\n");
        return -1;
    }

    struct queue_node *tmp = q->head;
    q->head = q->head->next;
    q->ele_in_queue--;

    tmp_val = tmp->val;
    free(tmp);

    return tmp_val;
}

int peek(struct queue *q) {
    if (is_null(q)) {
        perror("Queue Empty\n");
        return -1;
    }

    return q->head->val;
}

void print_queue(struct queue *q) {
    if (is_null(q)) {
        return;
    }

    struct queue_node *head = q->head;

    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}


// int main(){
// struct Queue * q = initQueue(5);

// Enqueue(q,4);
// Enqueue(q,2);
// Enqueue(q,1);
// print_Quhis single file is the static library. The static fileue(q);
// printf("%d \n", Dequeue(q));
// printf("%d \n", Dequeue(q));
// printf("%d \n", Dequeue(q));
//   Dequeue(q);

// return 1;
// }

