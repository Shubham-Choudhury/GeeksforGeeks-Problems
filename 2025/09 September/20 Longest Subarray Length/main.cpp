// Link: https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> nextGreater(n, n);
        vector<int> prevGreater(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++)
        {
            int windowSize = nextGreater[i] - prevGreater[i] - 1;
            if (windowSize >= arr[i])
            {
                maxLength = max(maxLength, windowSize);
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int result = sol.longestSubarray(arr);
    cout << "Length of the longest subarray: " << result << endl;

    arr = {6, 4, 2, 5};
    result = sol.longestSubarray(arr);
    cout << "Length of the longest subarray: " << result << endl;
    return 0;
}