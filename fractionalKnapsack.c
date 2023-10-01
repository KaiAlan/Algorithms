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

// Function to sort items based on their value-to-weight ratio (in descending order)
void sortItems(Item items[], int numItems) {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            double ratioA = items[j].value / (double)items[j].weight;
            double ratioB = items[j + 1].value / (double)items[j + 1].weight;
            if (ratioA < ratioB) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, Item items[], int numItems) {
    // Sort items by value-to-weight ratio in descending order
    sortItems(items, numItems);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the entire item can fit in the knapsack, add it
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If only a fraction of the item can fit, add the fraction
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * (double)remainingCapacity / items[i].weight;
            break; // The knapsack is full, so exit the loop
        }
    }

    return totalValue;
}

int main() {
    int capacity, numItems;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Dynamically allocate memory for an array of items
    Item* items = (Item*)malloc(numItems * sizeof(Item));

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Call the fractionalKnapsack function to solve the problem
    double maxValue = fractionalKnapsack(capacity, items, numItems);

    printf("Maximum value obtainable: %.2lf\n", maxValue);

    // Free dynamically allocated memory
    free(items);

    return 0;
}
