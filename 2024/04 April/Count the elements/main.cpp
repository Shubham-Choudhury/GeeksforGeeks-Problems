// Link: https://www.geeksforgeeks.org/problems/count-the-elements1529/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, max(a[i], b[i]));
        }

        int pre[mx + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            pre[b[i]] += 1;
        }

        for (int i = 1; i <= mx; i++)
        {
            pre[i] += pre[i - 1];
        }

        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int ind = query[i];
            int val = a[ind];
            ans.push_back(pre[val]);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {4, 1, 2};
    vector<int> b = {1, 7, 3};
    int n = a.size();
    vector<int> query = {0, 1};
    int q = query.size();
    vector<int> result = obj.countElements(a, b, n, query, q);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    a = {1, 1, 5, 5};
    b = {0, 1, 2, 3};
    n = a.size();
    query = {0, 1, 2, 3};
    q = query.size();
    result = obj.countElements(a, b, n, query, q);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}