// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis))
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> adj[V];
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    bool result = s.isCyclic(V, edges);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    V = 3;
    edges = {{0, 1}, {1, 2}};
    result = s.isCyclic(V, edges);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}