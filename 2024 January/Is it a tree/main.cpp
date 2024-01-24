// Link: https://www.geeksforgeeks.org/problems/is-it-a-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto j : adj[node])
        {
            if (!vis[j])
            {
                if (solve(j, node, adj, vis))
                    return true;
            }
            else if (parent != j)
                return true;
        }

        return false;
    }

    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        vector<int> pair[n];
        for (auto i : adj)
        {
            pair[i[0]].push_back(i[1]);
            pair[i[1]].push_back(i[0]);
        }

        vector<int> vis(n);
        bool res = false;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                res = res | solve(i, -1, pair, vis);
            }
        }

        if (count > 1 or res)
            return false;

        return true;
    }
};

int main()
{
    Solution obj;
    int N = 4;
    int M = 3;
    vector<vector<int>> adj = {{0, 1}, {1, 2}, {1, 3}};
    cout << obj.isTree(N, M, adj) << endl;
    return 0;
}