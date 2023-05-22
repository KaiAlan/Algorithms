#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    int* result = (int*)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1;
    }

    int totalProfit = 0;
    int jobCount = 0;
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        while (deadline > 0) {
            if (result[deadline - 1] == -1) {
                result[deadline - 1] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
            deadline--;
        }

        if (jobCount == maxDeadline) {
            break;
        }
    }

    printf("Optimal Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);

    free(result);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job* jobs = (Job*)malloc(n * sizeof(Job));

    printf("Enter the job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    free(jobs);

    return 0;
}
