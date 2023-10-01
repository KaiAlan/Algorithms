#include <stdio.h>
#include <stdlib.h>

// Function to perform BFS on a graph represented as an adjacency matrix
void bfs(int** adj, int size, int source) {
    // Create an array to keep track of visited vertices (initialized to all zeros)
    int* visited = (int*)calloc(size, sizeof(int));

    // Create a queue for BFS traversal
    int* queue = (int*)malloc(size * sizeof(int));
    int front = 0;
    int rear = 0;

    // Enqueue the source vertex and mark it as visited
    queue[rear++] = source;
    visited[source] = 1;

    // Perform BFS traversal
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex); // Print the current vertex

        // Explore adjacent vertices
        for (int i = 0; i < size; i++) {
            if (adj[currentVertex][i] == 1 && visited[i] == 0) {
                // If an adjacent vertex is not visited, enqueue it and mark it as visited
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    // Free dynamically allocated memory
    free(queue);
    free(visited);
}

int main() {
    int size;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the adjacency matrix
    int** adjacencyMatrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjacencyMatrix[i] = (int*)malloc(size * sizeof(int));
    }

    printf("Enter the adjacency matrix (%dx%d):\n", size, size);

    // Input the adjacency matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call the BFS function to perform traversal
    bfs(adjacencyMatrix, size, source);

    // Free dynamically allocated memory for the adjacency matrix
    for (int i = 0; i < size; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
