#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Useful when sorting floating point numbers
void bucketSort(float arr[], int n)
{
    // Create n buckets
    vector<float> b[n];

    // Put each element into the corresponding bucket based on its position in array
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // Sort each bucket using a stable sorting algorithm
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // Concatenate all the buckets to get the final answer
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
