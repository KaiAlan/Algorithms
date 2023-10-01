#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort function
void selectionSort(int arr[], int size) {
    int minIndex;

    // Iterate through the array
    for (int i = 0; i < size - 1; i++) {
        minIndex = i; // Assume the current index contains the minimum element

        // Find the index of the minimum element in the unsorted portion of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the current element with the minimum element found
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size 'n'

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Input 'n' integers into the array
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, n);

    printf("Sorted list in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]); // Print the sorted array elements
    }

    return 0;
}
