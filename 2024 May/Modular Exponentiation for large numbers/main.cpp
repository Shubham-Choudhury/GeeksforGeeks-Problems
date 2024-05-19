// Link: https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        long long int ans = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n >>= 1;
        }
        return ans % M;
    }
};

int main()
{
    Solution obj;
    long long int x = 3;
    long long int n = 2;
    long long int M = 4;
    cout << obj.PowMod(x, n, M) << endl;

    x = 2;
    n = 6;
    M = 10;
    cout << obj.PowMod(x, n, M) << endl;

    return 0;
}