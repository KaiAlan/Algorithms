#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

// Comparison function to sort items based on value per unit weight in descending order
int compare(const void* a, const void* b) {
    double ratioA = (double)(((struct Item*)a)->value) / ((struct Item*)a)->weight;
    double ratioB = (double)(((struct Item*)b)->value) / ((struct Item*)b)->weight;
    if (ratioA < ratioB)
        return 1;
    else if (ratioA > ratioB)
        return -1;
    else
        return 0;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items based on value per unit weight in descending order
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0; // Current weight of the knapsack
    double totalValue = 0.0; // Total value of the items selected

    for (int i = 0; i < n; i++) {
        // If adding the current item does not exceed the weight capacity,
        // include the entire item and update the current weight and total value
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Otherwise, include a fraction of the current item to fill the knapsack
            int remainingWeight = W - currentWeight;
            double fraction = (double)remainingWeight / items[i].weight;
            currentWeight += remainingWeight;
            totalValue += fraction * items[i].value;
            break;
        }
    }

    // Return the total value of the items selected
    return totalValue;
}

int main() {
    struct Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120},
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    // Solve the fractional knapsack problem and get the maximum value
    double maximumValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value that can be achieved: %.2f\n", maximumValue);

    return 0;
}
