#include <stdio.h>
#include <stdlib.h>

void jobSequencing(int jobs[][3], int n) {
    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i][1] > maxDeadline) {
            maxDeadline = jobs[i][1];
        }
    }

    int result[maxDeadline]; // Array to store the job sequence
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1; // Initialize all slots as empty
    }

    // Sort jobs based on profits in descending order using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j][2] < jobs[j + 1][2]) {
                // Swap jobs based on profits
                int temp[3];
                temp[0] = jobs[j][0];
                temp[1] = jobs[j][1];
                temp[2] = jobs[j][2];
                jobs[j][0] = jobs[j + 1][0];
                jobs[j][1] = jobs[j + 1][1];
                jobs[j][2] = jobs[j + 1][2];
                jobs[j + 1][0] = temp[0];
                jobs[j + 1][1] = temp[1];
                jobs[j + 1][2] = temp[2];
            }
        }
    }

    int filledSlots = 0;     // Number of filled slots
    int totalProfit = 0;     // Total profit

    // Iterate through the sorted jobs and schedule them in the latest available slot
    for (int i = 0; i < n; i++) {
        int currentDeadline = jobs[i][1] - 1; // Index of the current job's deadline in the result array

        // Find the latest available slot before the deadline
        while (currentDeadline >= 0 && result[currentDeadline] != -1) {
            currentDeadline--;
        }

        // If a suitable slot is found, schedule the job
        if (currentDeadline >= 0) {
            result[currentDeadline] = jobs[i][0];      // Schedule the job in the slot
            filledSlots++;
            totalProfit += jobs[i][2];                  // Update the filled slot count and total profit
        }

        // If all slots are filled, exit the loop
        if (filledSlots == maxDeadline) {
            break;
        }
    }

    // Print the job sequence and total profit
    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }

    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    // Create a 2D array of jobs [id, deadline, profit]
    int jobs[][3] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Solve the job sequencing problem
    jobSequencing(jobs, n);

    return 0;
}
