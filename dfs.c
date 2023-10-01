#include<stdio.h>
#include<stdlib.h>

// Function to perform depth-first search (DFS) on a graph
void dfs(int source, int size, int** adj, int* visited) {
    // Mark the current source vertex as visited and print it
    visited[source] = 1;
    printf("%d ", source);

    // Explore adjacent vertices
    for (int i = 0; i < size; i++) {
        if (adj[source][i] == 1 && visited[i] == 0) {
            // If an adjacent vertex is not visited, recursively call DFS on it
            dfs(i, size, adj, visited);
        }
    }
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

    // Create an array to keep track of visited vertices (initialized to all zeros)
    int* visited = (int*)calloc(size, sizeof(int));

    printf("Enter the adjacency matrix (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call the DFS function to perform the depth-first search
    dfs(source, size, adjacencyMatrix, visited);

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
    free(visited);

    return 0;
}
