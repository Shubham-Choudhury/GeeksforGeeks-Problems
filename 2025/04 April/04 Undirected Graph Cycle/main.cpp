// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    bool bfs(int start, vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<pair<int, int>> q;

        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for (auto adjNode : adj[node])
            {
                if (!vis[adjNode])
                {
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                }
                else if (adjNode != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++)
        {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (bfs(i, adj, vis) == true)
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
    Solution obj;
    int V = 4;
    int E = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << boolalpha << obj.isCycle(V, edges) << endl;

    V = 4;
    E = 3;
    edges = {{0, 1}, {1, 2}, {2, 3}};
    cout << boolalpha << obj.isCycle(V, edges) << endl;

    return 0;
}