// Link: https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int n, int n0, int n1, int tot, string s, priority_queue<pair<int, string>> &pq)
    {
        if (n == 0)
        {
            pq.push({tot, s});
            return;
        }

        solve(n - 1, n0, n1 + 1, tot * 2 + 1, s + "1", pq);
        if (n1 > n0)
        {
            solve(n - 1, n0 + 1, n1, tot * 2, s + "0", pq);
        }
    }

    vector<string> NBitBinary(int n)
    {
        priority_queue<pair<int, string>> pq;
        solve(n, 0, 0, 0, "", pq);

        vector<string> v;

        while (!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }

        return v;
    }
};

int main()
{
    Solution obj;
    int n = 2;
    vector<string> ans = obj.NBitBinary(n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    n = 3;
    ans = obj.NBitBinary(n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}