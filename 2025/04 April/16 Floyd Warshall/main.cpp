// Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int V = dist.size();

        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> dist = {
        {0, 4, (int)1e8, 5, (int)1e8},
        {(int)1e8, 0, 1, (int)1e8, 6},
        {2, (int)1e8, 0, 3, (int)1e8},
        {(int)1e8, (int)1e8, 1, 0, 2},
        {1, (int)1e8, (int)1e8, 4, 0}};

    obj.floydWarshall(dist);
    for (const auto &row : dist)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    dist = {
        {0, -1, 2},
        {1, 0, (int)1e8},
        {3, 1, 0}};

    obj.floydWarshall(dist);
    for (const auto &row : dist)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}