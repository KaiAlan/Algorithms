#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Compare function used for sorting jobs based on profits in descending order
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to solve the job sequencing problem
void jobSequencing(struct Job jobs[], int n) {
    int maxDeadline = 0;

    // Find the maximum deadline among all jobs
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int result[maxDeadline];

    // Initialize all slots as empty
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1;
    }

    // Sort jobs based on profits in descending order
    qsort(jobs, n, sizeof(struct Job), compare);

    int filledSlots = 0;
    int totalProfit = 0;

    // Iterate through the sorted jobs and schedule them in the latest available slot
    for (int i = 0; i < n; i++) {
        int currentDeadline = jobs[i].deadline - 1;

        // Find the latest available slot before the deadline
        while (currentDeadline >= 0 && result[currentDeadline] != -1) {
            currentDeadline--;
        }

        // If a suitable slot is found, schedule the job
        if (currentDeadline >= 0) {
            result[currentDeadline] = jobs[i].id;
            filledSlots++;
            totalProfit += jobs[i].profit;
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
    // Create an array of jobs
    struct Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Solve the job sequencing problem
    jobSequencing(jobs, n);

    return 0;
}
