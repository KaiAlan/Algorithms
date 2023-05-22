#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

void BellmanFord(int V, int E, int source, Edge edges[]) {
    int* distance = (int*)malloc(V * sizeof(int));
    int* parent = (int*)malloc(V * sizeof(int));

    // Step 1: Initialize distance and parent arrays
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[source] = 0;

    // Step 2: Relax edges V - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Negative weight cycle detected. The graph contains a negative cycle.\n");
            free(distance);
            free(parent);
            return;
        }
    }

    // Step 4: Print the shortest paths
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, distance[i]);
        int j = i;
        while (j != source) {
            printf("%d ", j);
            j = parent[j];
        }
        printf("%d\n", source);
    }

    free(distance);
    free(parent);
}

int main() {
    int V, E, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    printf("Enter the edges with their weights(example-> 0 0 0):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    BellmanFord(V, E, source, edges);

    free(edges);

    return 0;
}
