#include <stdio.h>
#include <stdlib.h>


struct Stack_Node {
    int val;
    struct Node * next;
};

struct Stack {
    int Ele_in_queue;
    struct Node * head;
    struct Node * tail;
};


struct Stack * init_Stack(int n)
{

    struct Stack * q = (struct Stack *) malloc( sizeof( struct Static));

    if (q == NULL) {
        printf("cant aquire memory");
        exit(1);
    }

    q-> Ele_in_queue = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

int isNull(struct Stack * q)
{
    return q->head == NULL;
}




void Push(struct Stack *q,int n)
{
    

    struct  Stack_Node * cn = (struct  Stack_Node *) malloc (sizeof(struct  Stack_Node));

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


int Pop(struct Stack *q)
{
    int tmpVal;

    if (isNull(q)) {
        printf("Stack Empty");
        return -1;
    }


    struct  Stack_Node * tmp = q->tail;
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

    return q->tail->val;
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

