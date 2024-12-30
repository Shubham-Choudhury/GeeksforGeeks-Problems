// Link: https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIndexDiff(int a[], int n)
    {
        stack<pair<int, int>> st;
        for (int i = n - 1; i > -1; i--)
        {
            if (st.empty() || st.top().second < a[i])
                st.push({i, a[i]});
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().second >= a[i])
            {
                ans = max(ans, st.top().first - i);
                st.pop();
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    int a[] = {1, 10};
    int n = sizeof(a) / sizeof(a[0]);
    cout << obj.maxIndexDiff(a, n) << endl;
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    cout << obj.maxIndexDiff(arr, n1) << endl;
    return 0;
}