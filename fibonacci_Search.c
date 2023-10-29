#include <stdio.h> 
int min(int x, int y) { return (x <= y) ? x : y; } 

int fibMonaccianSearch(int arr[], int x, int n) 
{ 
    int mmi2 = 0; // (m-2)'th Fibonacci No. 
    int mmi1 = 1; // (m-1)'th Fibonacci No. 
    int mth = mmi2 + mmi1; // m'th Fibonacci 
  
    /* mth is going to store the smallest Fibonacci 
       Number greater than or equal to n */
    while (mth < n) { 
        mmi2 = mmi1; 
        mmi1 = mth; 
        mth = mmi2 + mmi1; 
    } 
  
    // Marks the eliminated range from front 
    int osf = -1; 
  
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When mth becomes 1, 
       fibMm2 becomes 0 */
    while (mth > 1) { 
        // Check if fibMm2 is a valid location 
        int i = min(osf + mmi2, n - 1); 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray array from osf to i */
        if (arr[i] < x) { 
            mth = mmi1; 
            mmi1 = mmi2; 
            mmi2 = mth - mmi1; 
            osf = i; 
        } 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray after i+1  */
        else if (arr[i] > x) { 
            mth = mmi2; 
            mmi1 = mmi1 - mmi2; 
            mmi2 = mth - mmi1; 
        } 
  
        /* element found. return index */
        else
            return i; 
    } 
  
    /* comparing the last element with x */
    if (mmi1 && arr[osf + 1] == x) 
        return osf + 1; 
  
    /*element not found. return -1 */
    return -1; 
} 
  
/* driver function */
int main(void) 
{ 
    int arr[] 
        = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 235; 
      int ind = fibMonaccianSearch(arr, x, n); 
  if(ind>=0) 
    printf("Found at index: %d",ind); 
  else
    printf("%d isn't present in the array",x); 
    return 0; 
}