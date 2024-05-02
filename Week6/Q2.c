#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) 
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) 
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int isbipartite(int graph[MAX_SIZE][MAX_SIZE], int V, int s) 
{
    int visited[MAX_SIZE];
    for (int i = 0; i < V; i++)
        visited[i] = -1;
    visited[s] = 1;
    struct Queue* qu = createQueue(V);
    enqueue(qu, s);
    while (!isEmpty(qu)) 
    {
        int u = dequeue(qu);
        if (graph[u][u] == 1)
            return 0;
        for (int v = 0; v < V; v++)
          {
            if (graph[u][v] && visited[v] == -1)
            {
                visited[v] = 1 - visited[u];
                enqueue(qu, v);
            } else if (graph[u][v] && visited[v] == visited[u])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int graph[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    if (isbipartite(graph, n, 0))
        printf("Bipartite\n");
    else
        printf("Not Bipartite\n");
    return 0;
}
