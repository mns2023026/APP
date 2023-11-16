#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node * next;
};

struct Queue {
    int number_ele;
    int Ele_in_queue;
    struct Node * head;
    struct Node * tail;
};


struct Queue * initQueue(int n)
{

    struct Queue * q = (struct Queue *) malloc( sizeof( struct Queue ) );

    if (q == NULL) {
        printf("cant aquire memory");
        exit(1);
    }

    q-> Ele_in_queue = 0;
    q->number_ele = n;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

int isNull(struct Queue * q)
{
    return q->head == NULL;
}

int isFull(struct Queue *q)
{
    return q->number_ele == q-> Ele_in_queue;
}


void Enqueue(struct Queue *q,int n)
{
    if (isFull(q)) {

    printf("Queue Full");

    return;
    }

    struct Node * cn = (struct Node *) malloc (sizeof(struct Node));

    if (cn == NULL) {
        printf("cant aquire memory");
        return;
    }

    cn->val = n;
    q-> Ele_in_queue++;

    if (q->head == NULL) {
        q->head = cn;
        q->tail = cn;
        return ;
    }

    q->tail->next = cn;
    q->tail = cn;
}


int Dequeue(struct Queue *q)
{
    int tmpVal;

    if (isNull(q)) {
        printf("Queue Empty");
        return -1;
    }

    struct Node * tmp = q->head;
    q -> head = q->head->next;
    q -> Ele_in_queue--;

    tmpVal = tmp->val;
    free(tmp);

    return tmpVal;
}


int Peek(struct Queue * q)
{
    if (isNull(q)) {
        printf("Queue Empty");
        return -1;
    }

    return q->head->val;
}

void print_Queue(struct Queue * q)
{
    if (isNull(q)) {
        return ;
    }

    struct Node * head = q->head;

    while (head) {

        printf("%d ",head->val);
        head = head->next;
    
    }

    printf("\n");
}


// int main(){
// struct Queue * q = initQueue(5);

// Enqueue(q,4);
// Enqueue(q,2);
// Enqueue(q,1);
// print_Queue(q);
// printf("%d \n", Dequeue(q));
// printf("%d \n", Dequeue(q));
// printf("%d \n", Dequeue(q));
//   Dequeue(q);

// return 1;
// }

