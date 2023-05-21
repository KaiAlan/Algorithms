#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 9999

void dijkstra(int** graph, int vertices, int source) {
    int* distance = (int*)malloc(vertices * sizeof(int));
    bool* visited = (bool*)malloc(vertices * sizeof(bool));

    // Initialize distance array and visited array
    for (int i = 0; i < vertices; i++) {
        distance[i] = INFINITY;
        visited[i] = false;
    }

    // Distance from source to itself is 0
    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        // Find the vertex with the minimum distance
        int minDistance = INFINITY;
        int minIndex = -1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update distances of the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            int weight = graph[minIndex][v];
            if (!visited[v] && weight != 0 &&
                distance[minIndex] != INFINITY &&
                distance[minIndex] + weight < distance[v]) {
                distance[v] = distance[minIndex] + weight;
            }
        }
    }

    // Print the shortest distances from the source vertex
    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }

    // Free dynamically allocated memory
    free(distance);
    free(visited);
}

int main() {
    int vertices, source;

    // Get the number of vertices from the user
    printf("Enter the number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    // Get the source vertex from the user
    printf("Enter the source vertex (0 to %d): ", vertices - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= vertices) {
        printf("Invalid source vertex. Exiting...\n");
        return 1;
    }

    // Dynamically allocate memory for the graph
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Get the weighted adjacency array from the user
    printf("Enter the weighted adjacency array:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input. Exiting...\n");
                return 1;
            }
        }
    }

    dijkstra(graph, vertices, source);

    // Free dynamically allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
