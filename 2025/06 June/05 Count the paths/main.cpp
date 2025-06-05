// Link: https://www.geeksforgeeks.org/problems/count-the-paths4332/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int countPaths(vector<vector<int>> &edges, int V, int src, int dest)
    {
        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (int nei : graph[node])
            {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        vector<int> dp(V, 0);
        dp[dest] = 1;

        for (int i = V - 1; i >= 0; i--)
        {
            int node = topo[i];
            for (int nei : graph[node])
            {
                dp[node] += dp[nei];
            }
        }

        return dp[src];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {2, 0}, {2, 1}, {1, 3}};
    int V = 4, src = 2, dest = 3;
    int result = sol.countPaths(edges, V, src, dest);
    cout << "Number of paths from " << src << " to " << dest << ": " << result << endl;

    edges = {{0, 1}, {1, 2}, {1, 3}, {2, 3}};
    V = 4, src = 0, dest = 3;
    result = sol.countPaths(edges, V, src, dest);
    cout << "Number of paths from " << src << " to " << dest << ": " << result << endl;
    return 0;
}