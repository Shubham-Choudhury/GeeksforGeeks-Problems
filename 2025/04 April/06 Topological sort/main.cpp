// Link: https://www.geeksforgeeks.org/problems/topological-sort/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int V = 4;
    int E = 3;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    vector<int> result = obj.topoSort(V, edges);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    V = 6;
    E = 6;
    edges = {{1, 3},
             {2, 3},
             {4, 1},
             {4, 0},
             {5, 0},
             {5, 2}};
    result = obj.topoSort(V, edges);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}