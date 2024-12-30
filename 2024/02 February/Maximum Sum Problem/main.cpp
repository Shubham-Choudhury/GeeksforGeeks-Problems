// Link: https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help(int n)
    {
        if (n == 0)
            return 0;

        int sum = help(n / 2) + help(n / 3) + help(n / 4);

        if (sum >= n)
            return sum;
        else
            return n;
    }
    int maxSum(int n)
    {
        return help(n);
    }
};

int main()
{
    Solution obj;
    int n = 12;
    cout << obj.maxSum(n) << endl;
    n = 24;
    cout << obj.maxSum(n) << endl;
    return 0;
}