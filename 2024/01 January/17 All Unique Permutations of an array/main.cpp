// Link: https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i, set<vector<int>> &ans, vector<int> &arr)
    {
        if (i >= arr.size())
            return;
        set<vector<int>> temp;
        solve(i + 1, temp, arr);
        for (auto it : temp)
        {
            vector<int> v2;
            v2.push_back(arr[i]);
            for (int j = 0; j < it.size(); j++)
                v2.push_back(it[j]);
            for (int j = 0; j < (v2.size() - 1); j++)
            {
                ans.insert(v2);
                swap(v2[j], v2[j + 1]);
            }
            ans.insert(v2);
        }
        if (temp.size() == 0)
        {
            vector<int> v2;
            v2.push_back(arr[i]);
            ans.insert(v2);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        set<vector<int>> ans;
        solve(0, ans, arr);
        vector<vector<int>> result;
        for (auto it : ans)
            result.push_back(it);
        return result;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    vector<int> arr = {1, 2, 1};
    vector<vector<int>> result = obj.uniquePerms(arr, n);
    for (auto it : result)
    {
        for (auto it2 : it)
            cout << it2 << " ";
        cout << endl;
    }
    cout << endl;
    n = 2;
    arr = {4, 5};
    result = obj.uniquePerms(arr, n);
    for (auto it : result)
    {
        for (auto it2 : it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}