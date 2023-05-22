#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX 999

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mst[], int V) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++) {
        if (mst[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to perform Prim's algorithm to find the minimum spanning tree
void primMST(int **graph, int V) {
    // Allocate memory for parent array, key array, and MST set array
    int *parent = (int *)malloc(V * sizeof(int));     // Stores the parent of each vertex in the minimum spanning tree
    int *key = (int *)malloc(V * sizeof(int));        // Stores the key values used to pick the minimum weight edge
    bool *mstSet = (bool *)malloc(V * sizeof(bool));  // Tracks the vertices included in the minimum spanning tree

    // Initialize key values, MST set, and parent array
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;     // Set all key values to infinity initially
        mstSet[i] = false;    // Set all vertices as not included in MST set
    }

    key[0] = 0;  // Start with the first vertex
    parent[0] = -1; // First vertex is the root of MST

    // Find the minimum spanning tree
    for (int i = 0; i < V; i++) {
        int minIndex = minKey(key, mstSet, V); // Find the vertex with the minimum key value
        mstSet[minIndex] = true; // Include the vertex in the MST set

        // Update key and parent for adjacent vertices if they are not in MST set
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] != 0 && !mstSet[v] && key[v] > graph[minIndex][v]) {
                key[v] = graph[minIndex][v];    // Update the key value
                parent[v] = minIndex;           // Set the parent of the vertex
            }
        }
    }

    // Print the minimum spanning tree
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }

    // Free dynamically allocated memory
    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for the adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call the Prim's algorithm function
    primMST(graph, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
