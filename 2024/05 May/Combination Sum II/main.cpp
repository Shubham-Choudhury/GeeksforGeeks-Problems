// Link: https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;

    void solve(vector<int> &arr, int index, vector<int> &path, long long sum, int k)
    {
        if (sum >= k)
        {
            if (sum == k)
                ans.push_back(path);

            return;
        }
        if (index >= arr.size())
        {
            return;
        }

        path.push_back(arr[index]);
        solve(arr, index + 1, path, sum + arr[index], k);
        path.pop_back();

        while (index + 1 < arr.size() && arr[index] == arr[index + 1])
            index++;

        solve(arr, index + 1, path, sum, k);
    }

public:
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        sort(arr.begin(), arr.end());
        vector<int> path;
        long long sum = 0;
        solve(arr, 0, path, sum, k);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 3, 5};
    int n = arr.size();
    int k = 7;
    vector<vector<int>> ans = obj.CombinationSum2(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << endl;

    arr = {5, 10, 15, 20, 25, 30};
    n = arr.size();
    k = 30;
    ans = obj.CombinationSum2(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << endl;

    return 0;
}