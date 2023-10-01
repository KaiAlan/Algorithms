#include <stdio.h>

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

    quick_sort(array, 0, 7);

    printf("Sorted array:\n");

    for(int i = 0; i < 8; i++)
    {
        printf("%d\t", array[i]);
    }

    printf("\n");

    return 0;
}

void quick_sort(int array[], int low, int high)
{
    if(low >= high)
        return;

    int pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int index = low;

    for (int i = low; i < high; i++)
    {
        if(array[i] < pivot)
        {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
            index++;
        }
    }

    int temp = array[index];
    array[index] = pivot;
    array[high] = temp;

    return index;
}
