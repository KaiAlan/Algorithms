#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

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

double fractionalKnapsack(int capacity, Item items[], int numItems) {
    sortItems(items, numItems);

    int currentWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * (double)remainingCapacity / items[i].weight;
            break;
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

    Item* items = (Item*)malloc(numItems * sizeof(Item));

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    double maxValue = fractionalKnapsack(capacity, items, numItems);

    printf("Maximum value obtainable: %.2lf\n", maxValue);

    free(items);

    return 0;
}
