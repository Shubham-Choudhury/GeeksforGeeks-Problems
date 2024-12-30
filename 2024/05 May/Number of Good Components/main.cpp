// Link: https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int src, vector<int> &visited, vector<vector<int>> &graph,
             int &numberOfNodesInComponent, int size, bool &ans)
    {

        visited[src] = 1;
        numberOfNodesInComponent++;

        for (auto it : graph[src])
        {
            if (graph[it].size() != size)
                ans = false;
            if (visited[it] == 0)
                dfs(it, visited, graph, numberOfNodesInComponent, size, ans);
        }
    }

    bool isGoodComponent(int src, vector<int> &visited, vector<vector<int>> &graph)
    {
        int numberOfNodesInComponent = 0;
        int size = graph[src].size();
        bool ans = true;
        dfs(src, visited, graph, numberOfNodesInComponent, size, ans);

        if (size == numberOfNodesInComponent - 1 && ans == true)
            return true;
        return false;
    }

public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(v + 1);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int ans = 0;
        vector<int> visited(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (visited[i] == 0)
            {
                if (isGoodComponent(i, visited, graph))
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}};
    int e = edges.size();
    int v = 3;
    cout << obj.findNumberOfGoodComponent(e, v, edges) << endl;

    edges = {{1, 2}, {7, 2}, {3, 5}, {3, 4}, {4, 5}};
    e = edges.size();
    v = 7;
    cout << obj.findNumberOfGoodComponent(e, v, edges) << endl;

    return 0;
}