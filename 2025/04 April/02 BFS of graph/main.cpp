// Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(0);
        vector<int> ans;
        int n = adj.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (auto it : adj[f])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = obj.bfs(adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    ans = obj.bfs(adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}