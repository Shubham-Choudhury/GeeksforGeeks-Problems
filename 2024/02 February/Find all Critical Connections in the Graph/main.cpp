// Link: https://www.geeksforgeeks.org/problems/critical-connections/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int u, int parent, vector<int> &disc, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges, int &time)
    {
        disc[u] = low[u] = time++;

        for (int v : adj[u])
        {
            if (disc[v] == -1)
            {
                dfs(v, u, disc, low, adj, bridges, time);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u])
                {
                    bridges.push_back({min(u, v), max(u, v)});
                }
            }
            else if (v != parent)
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[])
    {
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        vector<vector<int>> bridges;
        int time = 0;

        for (int i = 0; i < v; ++i)
        {
            if (disc[i] == -1)
            {
                dfs(i, -1, disc, low, adj, bridges, time);
            }
        }
        sort(bridges.begin(), bridges.end());
        return bridges;
    }
};

int main()
{
    Solution obj;
    int v = 4;
    vector<int> adj[v];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(2);
    vector<vector<int>> res = obj.criticalConnections(v, adj);
    for (auto i : res)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}