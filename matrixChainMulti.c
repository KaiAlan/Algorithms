#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

// Function to print the optimal order of matrix multiplication
void printOptimalOrder(int split[][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalOrder(split, i, split[i][j]);
        printOptimalOrder(split, split[i][j] + 1, j);
        printf(")");
    }
}

// Function to solve the matrix chain multiplication problem
void matrixChainMultiplication(int dimensions[], int n) {
    int m[MAX_SIZE][MAX_SIZE]; // Store the minimum number of scalar multiplications
    int split[MAX_SIZE][MAX_SIZE]; // Store the split point for optimal order

    // Initialize the matrices for single matrices
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Calculate the minimum number of scalar multiplications for each subchain length
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX; // Initialize to a large value

            for (int k = i; k < j; k++) {
                // Calculate the cost of multiplying subchains
                int cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                
                // Update the minimum cost and split point if this configuration is better
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    // Print the minimum number of scalar multiplications
    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);

    // Print the optimal multiplication order
    printf("Optimal multiplication order: ");
    printOptimalOrder(split, 1, n);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[MAX_SIZE];
    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &dimensions[i]);
    }

    // Call the matrixChainMultiplication function to find the optimal order
    matrixChainMultiplication(dimensions, n);

    return 0;
}
