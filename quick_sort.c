#include <stdio.h>

// Function prototypes
void quick_sort(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    int array[] = {2, 4, 1, 2, 6, 5, 6, 9};

    printf("Original array:\n");

    for(int i = 0; i < 8; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("\n");

    // Call the quick_sort function to sort the array
    quick_sort(array, 0, 7);

    printf("Sorted array:\n");

    for(int i = 0; i < 8; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("\n");

    return 0;
}

// Quick Sort function
void quick_sort(int array[], int low, int high)
{
    // Base case: If there's only one element or no elements, return
    if(low >= high)
        return;

    // Partition the array and get the pivot's index
    int pivot = partition(array, low, high);

    // Recursively sort the left and right subarrays
    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
}

// Partitioning function
int partition(int array[], int low, int high)
{
    // Choose the pivot element (in this case, the rightmost element)
    int pivot = array[high];
    int index = low;

    // Iterate through the array
    for (int i = low; i < high; i++)
    {
        if(array[i] < pivot)
        {
            // Swap array[i] and array[index]
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;

            // Move the index to the right
            index++;
        }
    }

    // Swap the pivot element with the element at index
    int temp = array[index];
    array[index] = pivot;
    array[high] = temp;

    // Return the index where the pivot now resides
    return index;
}
