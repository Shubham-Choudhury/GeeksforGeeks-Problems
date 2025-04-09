// Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; ++i)
        {
            int u = -1;
            for (int j = 0; j < n; ++j)
            {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u]))
                    u = j;
            }

            totalCost += minDist[u];
            inMST[u] = true;

            for (int v = 0; v < n; ++v)
            {
                if (!inMST[v])
                {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (dist < minDist[v])
                        minDist[v] = dist;
                }
            }
        }

        return totalCost;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> houses = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << sol.minCost(houses) << endl;

    houses = {{0, 0}, {1, 1}, {1, 3}, {3, 0}};
    cout << sol.minCost(houses) << endl;
    return 0;
}