#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a class to represent a directed graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices), adj(vertices) {} // Constructor to initialize the graph with a given number of vertices

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Function to add an edge from vertex u to vertex v in the graph
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0); // Create a vector to store in-degrees of vertices, initialized to 0
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++; // Calculate in-degrees by traversing the adjacency list
            }
        }

        queue<int> q; // Create a queue for BFS
        for (int u = 0; u < V; ++u) {
            if (inDegree[u] == 0) {
                q.push(u); // Add vertices with in-degree 0 to the queue
            }
        }

        vector<int> topoOrder; // Create a vector to store the topological ordering
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u); // Add the current vertex to the topological ordering

            // Reduce in-degree of adjacent vertices
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v); // If in-degree becomes 0, add the vertex to the queue
                }
            }
        }

        if (topoOrder.size() != V) {
            cout << "The graph contains a cycle!" << endl; // If the topological ordering size is less than the number of vertices, there is a cycle
            return vector<int>();
        }

        return topoOrder; // Return the topological ordering of the graph
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E; // Input the number of vertices and edges
    Graph graph(V); // Create a graph with V vertices

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v); // Input edges (u, v) and add them to the graph
    }

    vector<int> topoOrder = graph.topologicalSort(); // Perform topological sorting

    if (!topoOrder.empty()) {
        for (int u : topoOrder) {
            cout << u << " "; // Print the topological ordering
        }
        cout << endl;
    }

    return 0;
}
