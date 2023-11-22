#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Stack_Node {
    int val;
    struct Stack_Node * next;
};

struct Stack {
    int Ele_in_queue;
    struct Stack_Node * head;
    struct Stack_Node * tail;
};


struct Stack * init_Stack()
{

    struct Stack * q = (struct Stack *) malloc( sizeof( struct Stack));

    if (q == NULL) {
        perror("cant aquire memory");
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
        perror("cant aquire memory");
        return;
    }

    cn->val = n;
    cn->next=NULL;
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
        perror("Stack Empty");
        return -1;
    }


    struct  Stack_Node * tmp = q->tail;
    tmpVal=q->tail->val;
    if (q->tail == q-> head) {
        q->tail=NULL;
        q->head =NULL;
    } else {
        struct  Stack_Node * head=q->head;
        while(head && head->next->next )
        {

            head=head->next;
        }
        head->next = NULL;
    }

    q -> Ele_in_queue--;
    free(tmp);
    return tmpVal;
}


int Peek(struct Stack * q)
{
    if (isNull(q)) {
        perror("Queue Empty");
        return -1;
    }

    return q->tail->val;
}

void print_Stack(struct Stack * q)
{
    if (isNull(q)) {
        return ;
    }

    struct Stack_Node * head = q->head;
    printf(".....Stack.....\n");
    while (head) {

        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n...............");

    printf("\n");
}


// int main()
// {
//     struct Stack * s=init_Stack();
//     Push(s,5);
//     Push(s,2);
//     Push(s,3);
//     print_Stack(s);
//     Pop(s);
//     // Pop(s);
//     print_Stack(s);

//     return 0;
// }
