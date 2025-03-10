// Link: https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countWaysRec(int n, vector<int> &memo)
    {
        if (n == 0 || n == 1)
            return 1;

        if (memo[n] != -1)
            return memo[n];

        return memo[n] = countWaysRec(n - 1, memo) +
                         countWaysRec(n - 2, memo);
    }

    int countWays(int n)
    {
        vector<int> memo(n + 1, -1);
        return countWaysRec(n, memo);
    }
};

int main()
{
    Solution obj;
    int n = 1;
    cout << obj.countWays(n) << endl;

    n = 2;
    cout << obj.countWays(n) << endl;

    n = 4;
    cout << obj.countWays(n) << endl;
    return 0;
}