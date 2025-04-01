// Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &visited, vector<vector<int>> &adj, int i, vector<int> &ans)
    {
        ans.push_back(i);
        visited[i] = 1;
        for (int next : adj[i])
        {
            if (!visited[next])
            {
                solve(visited, adj, next, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> ans;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                solve(visited, adj, i, ans);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = obj.dfs(adj);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    ans = obj.dfs(adj);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}