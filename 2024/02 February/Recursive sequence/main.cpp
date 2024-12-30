// Link: https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sequence(int n)
    {
        long long ans = 0, start = 1;
        for (long long i = 1; i <= n; ++i)
        {
            long long temp = 1, k = start;
            for (long long j = 1; j <= i; ++j)
            {
                temp *= k;
                temp %= 1000000007;
                ++k;
            }
            ans += temp;
            ans %= 1000000007;
            start = k;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n;
    n = 5;
    cout << obj.sequence(n) << endl;
    n = 7;
    cout << obj.sequence(n) << endl;
    return 0;
}