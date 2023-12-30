// Link: https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> winner(string arr[], int n)
    {
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        vector<string> v(2);
        int max = 0;
        string name;
        for (auto it : m)
        {
            if (it.second > max)
            {
                name = it.first;
                max = it.second;
            }
        }
        string asNum = to_string(max);
        v[0] = name;
        v[1] = asNum;
        return v;
    }
};

int main()
{
    Solution obj;
    int n = 13;
    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};
    vector<string> ans = obj.winner(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}