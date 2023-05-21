#include <stdio.h>
#include <stdlib.h>

void bfs(int** adj, int size, int source) {
    int* visited = (int*)calloc(size, sizeof(int));
    int* queue = (int*)malloc(size * sizeof(int));
    int front = 0;
    int rear = 0;

    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < size; i++) {
            if (adj[currentVertex][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    free(queue);
    free(visited);
}

int main() {
    int size;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &size);

    int** adjacencyMatrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjacencyMatrix[i] = (int*)malloc(size * sizeof(int));
    }

    printf("Enter the adjacency matrix (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bfs(adjacencyMatrix, size, source);

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
