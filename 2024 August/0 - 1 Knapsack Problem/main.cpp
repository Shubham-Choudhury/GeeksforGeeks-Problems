// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int solve(int W, vector<int> &wt, vector<int> &val, int sum, int &n, int i)
    {
        if (i >= n)
        {
            return sum;
        }
        if (W - wt[i] >= 0)
        {
            int taken = solve(W - wt[i], wt, val, sum + val[i], n, i + 1);
            int notTaken = solve(W, wt, val, sum, n, i + 1);
            return max(taken, notTaken);
        }
        else
        {
            int notTaken = solve(W, wt, val, sum, n, i + 1);
            return max(sum, notTaken);
        }
    }

public:
    int knapSack(int W, vector<int> &wt, vector<int> &val)
    {
        int sum = 0;
        int n = wt.size();
        int taken = solve(W, wt, val, sum, n, 0);
        int notTaken = solve(W, wt, val, sum, n, 1);
        return max(taken, notTaken);
    }
};

int main()
{
    Solution obj;
    vector<int> wt = {4, 5, 1};
    vector<int> val = {1, 2, 3};
    int W = 4;
    cout << obj.knapSack(W, wt, val) << endl;

    wt = {4, 5, 6};
    val = {1, 2, 3};
    W = 3;
    cout << obj.knapSack(W, wt, val) << endl;
    return 0;
}