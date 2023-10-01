#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a job with id, deadline, and profit
typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Comparison function for sorting jobs by profit in non-increasing order
int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Function to perform job sequencing and maximize profit
void jobSequencing(Job jobs[], int n) {
    // Sort the jobs in non-increasing order of profit using the qsort function
    qsort(jobs, n, sizeof(Job), compare);

    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create an array to store the selected job sequence
    int* result = (int*)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1; // Initialize all slots as empty (-1)
    }

    int totalProfit = 0;
    int jobCount = 0;

    // Iterate through the sorted jobs and assign them to time slots
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;

        // Find a suitable time slot for the current job (earliest available slot)
        while (deadline > 0) {
            if (result[deadline - 1] == -1) {
                // Assign the job to the time slot
                result[deadline - 1] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
            deadline--;
        }

        // If all time slots are filled, stop processing
        if (jobCount == maxDeadline) {
            break;
        }
    }

    // Print the optimal job sequence and total profit
    printf("Optimal Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    // Free dynamically allocated memory
    free(result);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of Job structures
    Job* jobs = (Job*)malloc(n * sizeof(Job));

    printf("Enter the job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Call the jobSequencing function to find the optimal sequence
    jobSequencing(jobs, n);

    // Free dynamically allocated memory
    free(jobs);

    return 0;
}
