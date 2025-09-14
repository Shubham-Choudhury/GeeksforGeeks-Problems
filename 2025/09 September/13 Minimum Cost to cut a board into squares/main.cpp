// Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(int n, int m, vector<int> &x, vector<int> &y)
    {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int hCount = 1, vCount = 1;
        int i = x.size() - 1, j = y.size() - 1;
        int totalCost = 0;

        while (i >= 0 && j >= 0)
        {
            if (x[i] >= y[j])
            {
                totalCost += x[i] * hCount;
                vCount++;
                i--;
            }
            else
            {
                totalCost += y[j] * vCount;
                hCount++;
                j--;
            }
        }

        while (i >= 0)
        {
            totalCost += x[i] * hCount;
            vCount++;
            i--;
        }

        while (j >= 0)
        {
            totalCost += y[j] * vCount;
            hCount++;
            j--;
        }

        return totalCost;
    }
};

int main()
{
    Solution sol;
    int n = 4, m = 6;
    vector<int> x = {2, 1, 3, 1, 4};
    vector<int> y = {4, 1, 2};
    int result = sol.minCost(n, m, x, y);
    cout << "Minimum cost to cut the board into squares: " << result << endl;

    n = 4, m = 4;
    x = {1, 1, 1};
    y = {1, 1, 1};
    result = sol.minCost(n, m, x, y);
    cout << "Minimum cost to cut the board into squares: " << result << endl;
    return 0;
}