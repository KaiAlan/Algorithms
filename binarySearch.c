#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int target) {
  // Check if the search range is valid
  if (low <= high) {
    // Calculate the middle index
    int mid = (low + high) / 2;

    // If the middle element is equal to the target, return its index
    if (arr[mid] == target) {
      return mid;
    }
    // If the middle element is less than the target, search in the right half
    else if (arr[mid] < target) {
      return binarySearch(arr, mid + 1, high, target);
    }
    // If the middle element is greater than the target, search in the left half
    else {
      return binarySearch(arr, low, mid - 1, target);
    }
  }
  // If the search range is not valid, return -1 (element not found)
  return -1;
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int target = 23;

  // Call the binarySearch function to search for the target element
  int index = binarySearch(arr, 0, 9, target);

  // Check the result of the search
  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index %d.\n", index);
  }

  return 0;
}
