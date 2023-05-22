#include <stdio.h>
#include <stdbool.h>

#define MAX_CITIES 10
#define INF 999999

void printOptimalPath(int path[], int cities) {
    printf("Optimal Path: ");
    for (int i = 0; i < cities; i++) {
        printf("%d", path[i]);
        if (i < cities - 1) {
            printf(" -> ");
        }
    }
    printf(" -> %d\n", path[0]);  // Return to the starting city
}

int tsp(int cities, int graph[MAX_CITIES][MAX_CITIES], bool visited[], int currentCity, int count, int cost, int path[]) {
    if (count == cities) {
        path[count - 1] = currentCity;
        return cost + graph[currentCity][0];  // Return to the starting city
    }

    int minDistance = INF;

    for (int city = 0; city < cities; city++) {
        if (!visited[city]) {
            visited[city] = true;
            path[count - 1] = currentCity;

            int newDistance = tsp(cities, graph, visited, city, count + 1, cost + graph[currentCity][city], path);
            if (newDistance < minDistance) {
                minDistance = newDistance;
            }

            visited[city] = false;
            path[count - 1] = -1;
        }
    }

    return minDistance;
}

int main() {
    int cities;
    printf("Enter the number of cities: ");
    scanf("%d", &cities);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool visited[MAX_CITIES] = {false};
    int path[MAX_CITIES];

    visited[0] = true;  // Mark the starting city as visited

    int minDistance = tsp(cities, graph, visited, 0, 1, 0, path);

    printf("Minimum Distance: %d\n", minDistance);
    // printOptimalPath(path, cities);

    return 0;
}
