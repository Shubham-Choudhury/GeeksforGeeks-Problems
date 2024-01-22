// Link: https://www.geeksforgeeks.org/problems/course-schedule/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        vector<int> adj[n];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        int indegree[n] = {0};
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
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

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (topo.size() == n)
            return topo;
        return {};
    }
};

int main()
{
    Solution obj;
    int n = 2;
    int m = 1;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<int> ans = obj.findOrder(n, m, prerequisites);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    n = 4;
    m = 4;
    prerequisites = {{1, 0},
                     {2, 0},
                     {3, 1},
                     {3, 2}};
    ans = obj.findOrder(n, m, prerequisites);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}