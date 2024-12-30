// Link: https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMaxDiff(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> right;
        stack<int> s1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s1.empty())
            {
                right.push_back(0);
            }
            else
            {
                while (!s1.empty() && arr[s1.top()] >= arr[i])
                {
                    s1.pop();
                }
                if (s1.empty())
                {
                    right.push_back(0);
                }
                else
                {
                    right.push_back(arr[s1.top()]);
                }
            }
            s1.push(i);
        }
        reverse(right.begin(), right.end());

        vector<int> left;
        stack<int> s2;
        for (int i = 0; i < n; i++)
        {
            if (s2.empty())
            {
                left.push_back(0);
            }
            else
            {
                while (!s2.empty() && arr[s2.top()] >= arr[i])
                {
                    s2.pop();
                }
                if (s2.empty())
                {
                    left.push_back(0);
                }
                else
                {
                    left.push_back(arr[s2.top()]);
                }
            }
            s2.push(i);
        }

        int maxDiff = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(right[i] - left[i]));
        }
        return maxDiff;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 1, 8};
    cout << obj.findMaxDiff(arr) << endl;
    arr = {2, 4, 8, 7, 7, 9, 3};
    cout << obj.findMaxDiff(arr) << endl;
    return 0;
}