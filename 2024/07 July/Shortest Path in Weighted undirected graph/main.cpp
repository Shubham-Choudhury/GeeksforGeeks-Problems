// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        vector<int> visited(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> parent(n + 1, -1);

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if (!visited[node])
            {
                visited[node] = true;
                for (auto v : adj[node])
                {
                    int nbr = v.first;
                    int weight = v.second;
                    if (dist[nbr] > dist[node] + weight)
                    {
                        dist[nbr] = dist[node] + weight;
                        pq.push({dist[nbr], nbr});
                        parent[nbr] = node;
                    }
                }
            }
        }

        if (parent[n] == -1)
            return {-1};
        vector<int> path;
        int t = n;
        while (t != -1)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int n = 5;
    int m = edges.size();
    vector<int> ans = obj.shortestPath(n, m, edges);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    edges = {{1, 2, 2}};
    n = 2;
    m = edges.size();
    ans = obj.shortestPath(n, m, edges);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    edges = {};
    n = 2;
    m = edges.size();
    ans = obj.shortestPath(n, m, edges);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}