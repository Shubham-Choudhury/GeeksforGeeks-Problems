// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist(N, INT_MAX);

        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node.second < dist[node.first])
                dist[node.first] = node.second;

            for (auto it : adj[node.first])
            {
                if (node.second + 1 < dist[it])
                {
                    dist[it] = node.second + 1;
                    q.push({it, node.second + 1});
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

int main()
{
    Solution obj;
    int n = 9;
    int m = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    int src = 0;
    vector<int> ans = obj.shortestPath(edges, n, m, src);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    n = 4;
    m = 2;
    edges = {{1, 3}, {3, 0}};
    src = 3;

    ans = obj.shortestPath(edges, n, m, src);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}