// Link: https://www.geeksforgeeks.org/problems/vertex-cover/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int k, int n, int m, vector<vector<int>> &arr)
    {
        int set = (1 << k) - 1;
        int limit = (1 << n);
        int visit[n + 1][n + 1];
        while (set < limit)
        {
            memset(visit, 0, sizeof(visit));
            int cnt = 0;
            for (int j = 1, v = 1; j < limit; j = j << 1, v++)
            {
                if (set & j)
                {
                    for (int k = 1; k <= n; k++)
                    {
                        if (arr[v][k] and !visit[v][k])
                        {
                            visit[v][k] = 1;
                            visit[k][v] = 1;
                            cnt++;
                        }
                    }
                }
            }

            if (cnt == m)
                return true;
            int col = set & -set;
            int row = set + col;

            set = (((row ^ set) >> 2) / col) | row;
        }
        return false;
    }
    int solve(vector<vector<int>> arr, int n, int m)
    {
        int start = 1;
        int end = n;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (check(mid, n, m, arr) == true)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
    int vertexCover(int n, vector<pair<int, int>> &edges)
    {
        int m = edges.size();
        vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            arr[edges[i].first][edges[i].second] = 1;
            arr[edges[i].second][edges[i].first] = 1;
        }
        return solve(arr, n, m);
    }
};

int main()
{
    Solution obj;
    int N = 5;
    int M = 6;
    vector<pair<int, int>> edges1 = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    cout << obj.vertexCover(N, edges1) << endl;
    N = 2;
    M = 1;
    vector<pair<int, int>> edges2 = {{1, 2}};
    cout << obj.vertexCover(N, edges2) << endl;
    return 0;
}