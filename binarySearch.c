#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
  if (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      return binarySearch(arr, mid + 1, high, target);
    } else {
      return binarySearch(arr, low, mid - 1, target);
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int target = 23;
  int index = binarySearch(arr, 0, 9, target);
  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index %d.\n", index);
  }
  return 0;
}