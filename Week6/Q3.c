#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


int graph[MAX_VERTICES][MAX_VERTICES]; 
int visited[MAX_VERTICES]; 
int stack[MAX_VERTICES]; 
int top = -1;


int dfs(int vertex, int num_vertices)
{
    visited[vertex] = 1; 
    stack[++top] = vertex; 

    
    for (int i = 0; i < num_vertices; i++)
      {
        if (graph[vertex][i]) 
        {
            if (!visited[i])
            {
                
                if (dfs(i, num_vertices))
                {
                    return 1; 
                }
            }
            else if (visited[i] && i != stack[top - 1])
            {
                return 1; 
            }
        }
    }

    top--;
    return 0;
}


int hasCycle(int num_vertices) 
{
    for (int i = 0; i < num_vertices; i++)
      {
        visited[i] = 0;
      }

    for (int i = 0; i < num_vertices; i++) 
    {
        if (!visited[i]) 
        {
            if (dfs(i, num_vertices)) 
            {
                return 1; 
            }
        }
    }

    return 0; 
}

int main() 
{
    int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) 
    {
        for (int j = 0; j < num_vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasCycle(num_vertices))
    {
      printf("Yes ycle Exists");
    }
    else
    {
        printf("No cycle Exists");
    }
return 0;
}
