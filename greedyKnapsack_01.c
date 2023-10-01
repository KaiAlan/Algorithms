#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent items with weight and value
typedef struct {
    int weight;
    int value;
} Item;

// Function to swap two items
void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value-to-weight ratio in descending order
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to solve the 0/1 knapsack problem using a greedy approach
void greedyKnapsack(int capacity, Item items[], int n) {
    // Sort items by value-to-weight ratio in descending order
    sortByRatio(items, n);

    // Create an array to track selected items (initialized to zeros)
    int* selected = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the item can fit in the knapsack, select it
            selected[i] = 1;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    // Print the selected items and total weight/value
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Total Weight: %d\n", currentWeight);
    printf("Total Value: %.2lf\n", totalValue);

    free(selected);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Dynamically allocate memory for an array of items
    Item* items = (Item*)malloc(n * sizeof(Item));

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Call the greedyKnapsack function to solve the problem
    greedyKnapsack(capacity, items, n);

    // Free dynamically allocated memory
    free(items);

    return 0;
}
