// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> countSort(vector<int>& arr){

    int len = arr.size();
    int mx = 0;
    
    for (int i = 0; i < len; i++){
        mx = max(mx, arr[i]); //finding max of the given array
    }
    vector<int> count_arr(mx + 1, 0); //initialize count array
 
    for (int i = 0; i < len; i++){
        count_arr[arr[i]]++; //inputing all the values of arr in count_arr respective of their index
    }
    for (int i = 1; i <= mx; i++){
        count_arr[i] += count_arr[i - 1]; //prefix sum
    }
    vector<int> res_array(len); //initialize resultant array
 
    for (int i = len - 1; i >= 0; i--){
        res_array[count_arr[arr[i]] - 1] = arr[i]; // initalize the element actual position in the resultant array
 
        count_arr[arr[i]]--; //resuce the number of element in count_arr due to multiple element presnet in input array
    }
 
    return res_array; //return sorted output array
}
 
int main(){

    int n; //length of input array
    cout<<"enter the length of input array"; cin>>n;
    
    vector<int> arr ; // initializing input array 
    for(int i=0;i<n;i++){
        int temp; cin>>temp;
        arr.push_back(temp);
    }

    vector<int> res_array = countSort(arr); //func call "countsort"
 
    for (int i = 0; i < arr.size(); i++)
        cout << res_array[i] << " "; //display
 
    return 0;
}