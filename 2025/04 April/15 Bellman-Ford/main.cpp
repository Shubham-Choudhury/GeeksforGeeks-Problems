// Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V; i++)
        {

            for (vector<int> edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {

                    if (i == V - 1)
                        return {-1};

                    dist[v] = dist[u] + wt;
                }
            }
        }

        return dist;
    }
};

int main()
{
    Solution obj;
    int V = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int src = 0;
    vector<int> result = obj.bellmanFord(V, edges, src);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    V = 4;
    edges = {{0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}};
    src = 0;
    result = obj.bellmanFord(V, edges, src);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}