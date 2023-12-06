#include <stdio.h>
#include <stdlib.h>

int graph[100][100]; 
int visited[100];
int numNodes;

struct Node{
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front,*rear;
};

struct Queue* initQueue() {
    struct Queue * queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}

int isQueueEmpty(struct Queue * queue)
{
    if(queue->front == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * queue,int item)
{
    struct Node * node=(struct Node*)malloc(sizeof(struct Node));
    node->data =  item;
    node->next =  NULL;

    if(queue->rear == NULL){
        queue->rear = node;
        queue->front = node;
        return ;
    }

    queue->rear->next = node;
    queue->rear=node;
}

int dequeue(struct Queue * queue)
{
    if(isQueueEmpty(queue))
    {
        return -1;
    }

    struct Node* temp = queue->front;
    int item = temp->data;

    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return item;
}

void initgraph() {
    for(int i=0;i<numNodes;i++)
    {
        visited[i] =0;
        for(int j=0;j<numNodes;j++)
        {
            graph[i][j] =0;
        }
    }
}

void addNode(int i ,int j) {
    graph[i][j]=1;
    graph[j][i]=1;
}

void dfs(int node) {
    printf("%d ",node);
    visited[node]=1;
    for(int i=0; i<numNodes; i++)
    {
        if(graph[node][i] ==  1 && !visited[i])
        {
            dfs(i);
        }
    }

}

void bfs(int startNode)
{
    struct Queue * queue=initQueue();
    enqueue(queue, startNode);
    visited[startNode]=1;

    while(!isQueueEmpty(queue))
    {
        int current=dequeue(queue);
        printf("%d ",current);
        for(int i=0; i< numNodes; i++)
        {
            if(graph[current][i] == 1 && !visited[i])
            {
                visited[i]=1;
                enqueue(queue,i);
            }
        }
    }
}

int main(){

    int numEdges, startNode;
    scanf("%d %d",&numNodes,&numEdges );

    initgraph();
    for(int i=0;i<numEdges;i++)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        addNode(u,v);
    }

    for(int i=0;i<numNodes;i++){
        for(int j=0; j< numNodes;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    scanf("%d",&startNode);
    // dfs(startNode);
    bfs(startNode);
    return 0;
}

