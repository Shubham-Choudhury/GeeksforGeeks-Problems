// Link: https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int timer;
    vector<int> tin, low;
    bool foundBridge;

    void dfs(int node, int parent, vector<int> adj[], int c, int d)
    {
        tin[node] = low[node] = timer++;

        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;

            if (tin[neighbor] == -1)
            {
                dfs(neighbor, node, adj, c, d);
                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > tin[node])
                {
                    if ((node == c && neighbor == d) || (node == d && neighbor == c))
                        foundBridge = true;
                }
            }
            else
            {
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
    {
        vector<int> adj[V];

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        foundBridge = false;

        for (int i = 0; i < V; ++i)
        {
            if (tin[i] == -1)
                dfs(i, -1, adj, c, d);
        }

        return foundBridge;
    }
};

int main()
{
    Solution sol;
    int c = 1;
    int d = 2;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    cout << boolalpha << sol.isBridge(V, edges, c, d) << endl;

    c = 0;
    d = 2;
    V = 5;
    edges = {{0, 1}, {1, 2}, {0, 2}, {0, 3}, {3, 4}};
    cout << boolalpha << sol.isBridge(V, edges, c, d) << endl;

    return 0;
}