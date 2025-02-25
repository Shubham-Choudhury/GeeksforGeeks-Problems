// Link: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int getMaxArea(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n, -1);
        vector<int> nex(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nex[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] * (nex[i] - prev[i] - 1));
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << object.getMaxArea(arr) << endl;

    arr = {3, 5, 1, 7, 5, 9};
    cout << object.getMaxArea(arr) << endl;

    arr = {3};
    cout << object.getMaxArea(arr) << endl;
    return 0;
}