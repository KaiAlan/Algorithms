// STOCK SPAN PROBLEM
//  Given a series of N daily price quotes for a stock, we need to calculate the span of the stock’s price for all
//  N days. The span of the stock's price in one day is the maximum number of consecutive days (starting from
//  that day and going backward) for which the stock price was less than ok equal to the price of that day.

#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> arr) // similar to previous greater element
{
    reverse(arr.begin(), arr.end());

    vector<int> output(arr.size(), 1);
    stack<int> st;
    st.push(0);

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = (i - st.top());
            st.pop();
        }
        st.push(i);
    }

    // in case the stack is not empty and the element has no prev greater element
    // eg - 68 735 101 770
    // here 770 has no prev greater element so output[i] will store the default val = 1
    // it should store 4 i.e max no. of smaller element before the no. i.e 770
    // thus the following step is necessary

    while (!st.empty())
    {
        output[st.top()] = arr.size() - st.top();
        st.pop();
    }

    reverse(arr.begin(), arr.end());
    reverse(output.begin(), output.end());
    return output;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = StockSpan(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }
}

// Time Complexity = O(n);
// Space Complexity = O(n);