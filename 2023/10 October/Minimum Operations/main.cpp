// Link: https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperation(int n)
    {
        if (n == 1)
            return 1;
        if (n % 2 == 0)
            return minOperation(n / 2) + 1;

        else
        {
            return minOperation(n - 1) + 1;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.minOperation(8) << endl;
    cout << sol.minOperation(7) << endl;
    return 0;
}