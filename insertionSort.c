#include <stdio.h>

int main(void) {
    int n, i, j, temp;
    int arr[64];

    // Prompt the user to enter the number of elements in the array
    printf("Enter number of elements\n");
    scanf("%d", &n);

    // Prompt the user to enter 'n' integers
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // Swap adjacent elements if they are in the wrong order
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    // Print the sorted list in ascending order
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
