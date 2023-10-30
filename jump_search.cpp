#include <iostream>
#include <vector>
#include <cmath>

/**
 * Jump Search algorithm to search for a target element in a sorted array.
 *
 * @param arr The sorted array to be searched.
 * @param target The element to be searched for.
 * @return The index of the target element in the array, or -1 if not found.
 */
int jumpSearch(const std::vector<int> &arr, int target) {
    int n = arr.size();
    int blockSize = static_cast<int>(std::sqrt(n)); // Calculate the block size

    int left = 0;   // Initialize the left boundary of the current block
    int right = blockSize;  // Initialize the right boundary of the current block

    // Jump to the next block until the target is greater than the current block's upper bound
    while (right < n && arr[right] <= target) {
        left = right;
        right += blockSize;
        if (right > n)
            right = n; // Adjust right if it exceeds the array size
    }

    // Perform a linear search within the current block
    for (int i = left; i < right; i++) {
        if (arr[i] == target)
            return i;   // Target found
    }

    return -1;  // Target not found
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int target = 13;

    int result = jumpSearch(arr, target);

    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << std::endl;
    else
        std::cout << "Element " << target << " not found in the array." << std::endl;

    return 0;
}
