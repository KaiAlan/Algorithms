// Given an array of integer heights representing the histogram's bar height where the width of each bar is
// 1, return the area of the largest rectangle in the histogram.

#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> pse(vector<int> &arr) // similar to previous smaller element
{
    reverse(arr.begin(), arr.end());

    vector<int> output(arr.size(), -1);
    stack<int> st;
    st.push(0);

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            output[st.top()] = arr.size() - i - 1;
            st.pop();
        }
        st.push(i);
    }
    reverse(arr.begin(), arr.end());
    reverse(output.begin(), output.end());
    return output;
}

vector<int> nse(vector<int> &arr)
{
    int size = arr.size();
    stack<int> st;
    st.push(0);

    vector<int> output(size, arr.size()); // creating an output vector and initializing its values with -1

    for (int i = 1; i < size; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            output[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return output;
}

int maxArea(vector<int> h)
{
    vector<int> prev_smaller = pse(h);
    vector<int> next_smaller = nse(h);

    int max_area = 0;
    for (int i = 0; i < h.size(); i++)
    {

        // cout<<"height "<<h[i]<<endl;
        // cout<<"nextsmall "<<next_smaller[i]<<endl;
        // cout<<"prevsmall "<<prev_smaller[i]<<endl;
        // cout<<"width "<< (next_smaller[i]-prev_smaller[i]-1)<<endl;

        int area = h[i] * (next_smaller[i] - prev_smaller[i] - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << "Maximum Area : " << maxArea(height) << endl;

    return 0;
}

//Time Complexity = O(n);
//Space Complexity = O(n);