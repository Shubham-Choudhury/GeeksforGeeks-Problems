// Link: https://www.geeksforgeeks.org/problems/divisibility-tree1902/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int ans = 0;

    int dfs(vector<int> adj[], vector<int> &vis, int start)
    {
        vis[start] = 1;
        int cnt = 0;

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                int res = dfs(adj, vis, it);
                if (res % 2 == 0)
                {
                    ans++;
                }
                else
                {
                    cnt += res;
                }
            }
        }

        return cnt + 1;
    }

public:
    int minimumEdgeRemove(int n, vector<vector<int>> edges)
    {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        vector<int> vis(n, 0);

        dfs(adj, vis, 0);

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges = {{2, 1}, {3, 1}, {4, 3}, {5, 2}, {6, 1}, {7, 2}, {8, 6}, {9, 8}, {10, 8}};
    int n = 10;
    cout << obj.minimumEdgeRemove(n, edges) << endl;

    edges = {{2, 1}, {4, 2}, {1, 3}};
    n = 4;
    cout << obj.minimumEdgeRemove(n, edges) << endl;

    return 0;
}