// Link: https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> ans(n, 1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                ans[i] += ans[s.top()];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = object.calculateSpan(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    arr = {10, 4, 5, 90, 120, 80};
    ans = object.calculateSpan(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    arr = {11, 4, 5, 90, 120, 80};
    ans = object.calculateSpan(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
