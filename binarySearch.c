#include <stdio.h>

// Binary search function
// Parameters:
// - arr: The sorted array to search in
// - low: The low index of the current search range
// - high: The high index of the current search range
// - target: The target value to search for
int binarySearch(int arr[], int low, int high, int target) {
  if (low <= high) {
    int mid = (low + high) / 2; // Calculate the middle index
    if (arr[mid] == target) return mid; // Element found
    else if (arr[mid] < target) return binarySearch(arr, mid + 1, high, target); // Search in the right half
    else return binarySearch(arr, low, mid - 1, target); // Search in the left half
  }
  return -1; // Element not found
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int target = 23;
  int index = binarySearch(arr, 0, 9, target);
  if (index == -1) printf("Element not found.\n");
  else printf("Element found at index %d.\n", index);
  return 0;
}
