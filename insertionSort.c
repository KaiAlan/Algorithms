#include <stdio.h>

int main(void)
{
    int n, i, j, temp;
    int arr[64];
    
    // Prompt the user to enter the number of elements
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    // Prompt the user to enter integers
    printf("Enter %d integers\n", n);
    
    // Read integers into the array
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Perform insertion sort
    for (i = 1; i < n; i++) 
    {
        j = i;
        // Swap elements to sort the array in ascending order
        while (j > 0 && arr[j - 1] > arr[j]) 
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    
    // Print the sorted list in ascending order
    printf("Sorted list in ascending order:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
