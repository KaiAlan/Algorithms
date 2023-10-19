
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//searching algorithm works on only sorted array with uniform distribution 
int interpolationSearch(vector<int> &arr, int st, int ed, int x){
	int val;

	if (st <= ed && x >= arr[st] && x <= arr[ed]) {
        //Probing the position with keeping uniform distribution in mind.
		val = st + (((double)(ed - st) / (arr[ed] - arr[st]))* (x - arr[st]));
        
        // Condition of target found
		if (arr[val] == x)
			return val;

        // If x is larger, x is in right sub array
		if (arr[val] < x)
			return interpolationSearch(arr, val + 1, ed, x);

        // If x is smaller, x is in left sub array
		if (arr[val] > x)
			return interpolationSearch(arr, st, val - 1, x);
	}
	return -1;
}

int main(){
    vector<int> arr; //inttialize an array 
    int n;
    cin>>n; //get the array size
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;  //enter the elements in teh array
        arr.push_back(temp);
    }
    int x;  //define the target element
    cin>>x;

	int index = interpolationSearch(arr, 0, n - 1, x);

	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";

	return 0;
}