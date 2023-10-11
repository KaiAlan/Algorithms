// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// void printSolution(int** board, int N) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%c ", board[i][j] ? 'Q' : '-');
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// bool isSafe(int** board, int N, int row, int col) {
//     // Check if there is a queen in the same column
//     for (int i = 0; i < row; i++) {
//         if (board[i][col]) {
//             return false;
//         }
//     }

//     // Check if there is a queen in the upper-left diagonal
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//         if (board[i][j]) {
//             return false;
//         }
//     }

//     // Check if there is a queen in the upper-right diagonal
//     for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
//         if (board[i][j]) {
//             return false;
//         }
//     }

//     return true;
// }

// void solveNQueens(int** board, int N, int row) {
//     if (row == N) {
//         // All queens have been placed, print the solution
//         printSolution(board, N);
//         return;
//     }

//     // Try placing a queen in each column of the current row
//     for (int col = 0; col < N; col++) {
//         if (isSafe(board, N, row, col)) {
//             // Place the queen in the current position
//             board[row][col] = 1;

//             // Recursively solve for the next row
//             solveNQueens(board, N, row + 1);

//             // Backtrack and remove the queen from the current position
//             board[row][col] = 0;
//         }
//     }
// }

// int main() {
//     int N;
//     printf("Enter the board size (N): ");
//     scanf("%d", &N);

//     // Dynamically allocate memory for the board
//     int** board = (int**)malloc(N * sizeof(int*));
//     for (int i = 0; i < N; i++) {
//         board[i] = (int*)malloc(N * sizeof(int));
//         for (int j = 0; j < N; j++) {
//             board[i][j] = 0;
//         }
//     }

//     solveNQueens(board, N, 0);

//     // Free the dynamically allocated memory
//     for (int i = 0; i < N; i++) {
//         free(board[i]);
//     }
//     free(board);

//     return 0;
// }


#include <stdio.h>
#include <math.h>

int board[20], count;

int main()
{
    int n, i, j;
    void queen(int row, int n);

    printf("\n\nEnter the number of Queens:");
    scanf("%d", &n);

    queen(1, n);

    return 0;
}

void print(int n)
{
    int i, j;
    printf("\n\n Solution %d:\n\n", ++count);

    for (i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (board[1] == column)
            return 0;
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column;
            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}