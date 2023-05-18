#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1]; // DP table to store the maximum values

    // Build the DP table bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                // Base case: No items or no weight capacity, so the value is 0
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                // If the current item can be included, compute the maximum value
                // by either including the item or excluding it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // If the current item's weight exceeds the remaining weight capacity,
                // we cannot include the item, so the value is the same as the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value that can be achieved is stored in the bottom-right cell of the DP table
    return dp[n][W];
}

int main() {
    int weights[] = {10, 20, 30}; // Array of item weights
    int values[] = {60, 100, 120}; // Array of item values
    int W = 50; // Maximum weight capacity of the knapsack
    int n = sizeof(weights) / sizeof(weights[0]); // Total number of items

    // Solve the knapsack problem and find the maximum value
    int maxValue = knapsack(W, weights, values, n);
    printf("Maximum value that can be achieved: %d\n", maxValue);

    return 0;
}
