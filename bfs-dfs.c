#include <stdio.h>

// BFS function
void bfs(int s, int n, int adj[][20], int visited[]) {
  // Create a queue to store the vertices to be visited
  int queue[20];
  int front = 0;
  int rear = 0;

  // Mark the source vertex as visited
  visited[s] = 1;

  // Add the source vertex to the queue
  queue[rear++] = s;

  // While the queue is not empty
  while (front < rear) {
    // Get the vertex at the front of the queue
    int v = queue[front++];

    // Print the vertex
    printf("%d ", v);

    // For each adjacent vertex of v
    for (int i = 0; i < n; i++) {
      // If the adjacent vertex is not visited
      if (adj[v][i] == 1 && !visited[i]) {
        // Mark the adjacent vertex as visited
        visited[i] = 1;

        // Add the adjacent vertex to the queue
        queue[rear++] = i;
      }
    }
  }
}

// DFS function
void dfs(int s, int n, int adj[][20], int visited[]) {
  // Mark the source vertex as visited
  visited[s] = 1;

  // Print the source vertex
  printf("%d ", s);

  // For each adjacent vertex of s
  for (int i = 0; i < n; i++) {
    // If the adjacent vertex is not visited
    if (adj[s][i] == 1 && !visited[i]) {
      // Recursively call DFS on the adjacent vertex
      dfs(i, n, adj, visited);
    }
  }
}

int main() {
  // Number of vertices
  int n = 5;

  // Adjacency matrix
  int adj[20][20] = {{0, 1, 0, 0, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 1},
                     {0, 1, 0, 0, 1},
                     {0, 0, 1, 1, 0}};

  // Visited array
  int visited[20] = {0};

  // Source vertex
  int s = 0;


  // Print the DFS traversal
  printf("DFS traversal: ");
  dfs(s, n, adj, visited);
  printf("\n");

    s = 0;

  // Print the BFS traversal
  printf("BFS traversal: ");
  bfs(s, n, adj, visited);
  printf("\n");

  return 0;
}
