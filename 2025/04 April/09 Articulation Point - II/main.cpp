// Link: https://www.geeksforgeeks.org/problems/articulation-point2616/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &low, vector<int> &tn, vector<int> &mark)
    {
        visited[node] = 1;
        low[node] = tn[node] = timer;
        timer++;
        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, adj, visited, low, tn, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tn[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tn[it]);
            }
        }

        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        vector<int> visited(V, 0);
        vector<int> adj[V];
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> low(V), tn(V);
        vector<int> mark(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, adj, visited, low, tn, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }

        if (ans.empty())
            return {-1};
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
    vector<int> ans = sol.articulationPoints(V, edges);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    V = 4;
    edges = {{0, 1}, {0, 2}};
    ans = sol.articulationPoints(V, edges);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
