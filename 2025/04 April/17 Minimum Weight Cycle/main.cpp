// Link: https://www.geeksforgeeks.org/problems/minimum-weight-cycle/1

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> graph(V);
        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        const int INF = numeric_limits<int>::max();
        int min_cycle = INF;

        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].erase(remove(graph[u].begin(), graph[u].end(), make_pair(v, w)), graph[u].end());
            graph[v].erase(remove(graph[v].begin(), graph[v].end(), make_pair(u, w)), graph[v].end());

            vector<int> dist(V, INF);
            vector<bool> visited(V, false);
            dist[u] = 0;

            for (int i = 0; i < V; ++i)
            {
                int min_dist = INF;
                int min_node = -1;
                for (int j = 0; j < V; ++j)
                {
                    if (!visited[j] && dist[j] < min_dist)
                    {
                        min_dist = dist[j];
                        min_node = j;
                    }
                }

                if (min_node == -1)
                {
                    break;
                }

                visited[min_node] = true;

                for (const auto &neighbor : graph[min_node])
                {
                    int neighbor_node = neighbor.first;
                    int weight = neighbor.second;
                    if (!visited[neighbor_node] && dist[neighbor_node] > dist[min_node] + weight)
                    {
                        dist[neighbor_node] = dist[min_node] + weight;
                    }
                }
            }

            if (dist[v] != INF)
            {
                min_cycle = min(min_cycle, dist[v] + w);
            }

            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        return min_cycle != INF ? min_cycle : -1;
    }
};

int main()
{
    Solution obj;
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 2}, {1, 3, 1}, {1, 4, 1}, {0, 4, 3}, {2, 3, 4}};
    cout << obj.findMinCycle(V, edges) << endl;

    V = 5;
    edges = {
        {0, 1, 3},
        {1, 2, 2},
        {0, 4, 1},
        {1, 4, 2},
        {1, 3, 1},
        {3, 4, 2},
        {2, 3, 3},
    };
    cout << obj.findMinCycle(V, edges) << endl;

    return 0;
}