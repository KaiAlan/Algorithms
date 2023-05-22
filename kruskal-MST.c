#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

// Find the parent of a subset
int find(Subset subsets[], int i) {
    // Path compression: update parent to root
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two subsets
void unionSet(Subset subsets[], int x, int y) {
    // Union by rank: attach smaller rank tree under root of higher rank tree
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm to find the minimum spanning tree
void kruskalMST(int V, int E, Edge edges[]) {
    Edge result[MAX_EDGES];
    int resultIndex = 0;

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    // Initialize subsets with each vertex as a separate subset
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order of weights
    qsort(edges, E, sizeof(Edge), compare);

    int edgeIndex = 0;
    while (resultIndex < V - 1 && edgeIndex < E) {
        Edge nextEdge = edges[edgeIndex++];

        // Find the subsets of the source and destination vertices
        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        // If including this edge does not form a cycle, add it to the result
        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d \t%d\n", result[i].source, result[i].destination, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    Edge edges[MAX_EDGES];

    printf("Enter the edges with their weights:\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    kruskalMST(V, E, edges);

    return 0;
}
