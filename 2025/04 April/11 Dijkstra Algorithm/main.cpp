// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-edgesacency-matrix/1

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &i : edges)
        {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            int d = curr.first;
            int u = curr.second;

            if (d > dist[u])
                continue;

            for (const auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int w = neighbor.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main()
{
    Solution sol;
    int V = 3;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int src = 2;
    vector<int> result = sol.dijkstra(V, edges, src);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    V = 5;
    edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    src = 0;
    result = sol.dijkstra(V, edges, src);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
