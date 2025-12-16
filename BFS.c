#include <stdio.h>

int queue[50], front = -1, rear = -1;
int visited[50], n;
int graph[50][50];

/* Function to insert into queue */
void enqueue(int v)
{
    if (rear == 49)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

/* Function to delete from queue */
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

/* BFS function */
void bfs(int start)
{
    int i, v;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
