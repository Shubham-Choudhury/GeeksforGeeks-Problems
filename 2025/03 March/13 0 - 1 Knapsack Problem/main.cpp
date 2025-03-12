// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> vec(n + 1, vector<int>(W + 1, -1));
        for (int i = 0; i <= n; i++)
            vec[i][0] = 0;
        for (int i = 0; i <= W; i++)
            vec[0][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                    vec[i][j] = max(val[i - 1] + vec[i - 1][j - wt[i - 1]], vec[i - 1][j]);
                else
                    vec[i][j] = vec[i - 1][j];
            }
        return vec[n][W];
    }
};

int main()
{
    Solution obj;
    int W = 4;
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    cout << obj.knapsack(W, val, wt) << endl;

    W = 3;
    val = {1, 2, 3};
    wt = {4, 5, 6};
    cout << obj.knapsack(W, val, wt) << endl;

    W = 5;
    val = {10, 40, 30, 50};
    wt = {5, 4, 2, 3};
    cout << obj.knapsack(W, val, wt) << endl;
    return 0;
}