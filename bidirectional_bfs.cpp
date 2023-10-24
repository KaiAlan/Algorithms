// One of the best Searching Algorithms !!!
#include <bits/stdc++.h>
using namespace std;
// Function to perform a single step of BFS and return the neighbors of a node
vector<int> bfs_step(const vector<vector<int>>& graph, vector<bool>& visited, queue<int>& q, unordered_map<int, int>& parent) {
    vector<int> neighbors;
    int current = q.front();
    q.pop();
    visited[current] = true;
    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            parent[neighbor] = current;
            q.push(neighbor);
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

// Bidirectional BFS algorithm to find the shortest path between two nodes
vector<int> bidirectionalBFS(const vector<vector<int>>& graph, int start, int goal) {
    vector<bool> visited(graph.size(), false);
    queue<int> q_start, q_goal;
    unordered_map<int, int> parent_start, parent_goal;

    q_start.push(start);
    q_goal.push(goal);

    while (!q_start.empty() && !q_goal.empty()) {
        // Search from the start vertex
        vector<int> neighbors_start = bfs_step(graph, visited, q_start, parent_start);

        // Check if we found an intersection
        for (int neighbor : neighbors_start) {
            if (visited[neighbor]) {
                // Intersection found, reconstruct the path
                vector<int> path;
                int common_node = neighbor;
                while (common_node != start) {
                    path.push_back(common_node);
                    common_node = parent_start[common_node];
                }
                path.push_back(start);

                common_node = neighbor;
                while (common_node != goal) {
                    common_node = parent_goal[common_node];
                    path.push_back(common_node);
                }
                return path;
            }
        }

        // Search from the goal vertex
        vector<int> neighbors_goal = bfs_step(graph, visited, q_goal, parent_goal);

        // Check if we found an intersection
        for (int neighbor : neighbors_goal) {
            if (visited[neighbor]) {
                // Intersection found, reconstruct the path
                vector<int> path;
                int common_node = neighbor;
                while (common_node != goal) {
                    path.push_back(common_node);
                    common_node = parent_goal[common_node];
                }
                path.push_back(goal);

                common_node = neighbor;
                while (common_node != start) {
                    common_node = parent_start[common_node];
                    path.push_back(common_node);
                }
                return path;
            }
        }
    }

    // If no path exists
    return vector<int>();
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5, 6},
        {1},
        {1},
        {2},
        {2}
    };

    int start = 0;
    int goal = 6;
    vector<int> shortestPath = bidirectionalBFS(graph, start, goal);

    if (shortestPath.empty()) {
        cout << "No path exists between " << start << " and " << goal << endl;
    } else {
        cout << "Shortest path between " << start << " and " << goal << ": ";
        for (int node : shortestPath) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

// Advantages of Bidirectional BFS:

// Efficiency: Bidirectional BFS is more efficient than traditional BFS when searching for the shortest path between two vertices. It effectively reduces the search space by exploring from both the start and goal simultaneously, potentially leading to a significant reduction in the number of nodes visited.

// Faster Search: In most cases, Bidirectional BFS is faster than traditional BFS, especially in large graphs. It's ideal for applications where finding the shortest path quickly is crucial.

// Optimality: Bidirectional BFS guarantees that it will find the shortest path because it explores from both ends and stops when the two searches meet in the middle.

// Reduces Search Space: By searching from both directions, Bidirectional BFS reduces the branching factor of the search tree, which can make a big difference in terms of time complexity.

// Saves Memory: Since you don't need to store the entire search tree, Bidirectional BFS is often more memory-efficient compared to algorithms like A*.
