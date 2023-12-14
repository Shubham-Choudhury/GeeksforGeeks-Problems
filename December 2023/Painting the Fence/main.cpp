// Link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k + k * (k - 1) % 1000000007;

        long long mod = 1000000007;
        long long same = k;
        long long diff = (k % mod * (k - 1) % mod) % mod;
        long long total = (same % mod + diff % mod) % mod;

        for (long long i = 3; i <= n; i++)
        {
            same = diff % mod;
            diff = (total % mod * (k - 1) % mod) % mod;
            total = (same % mod + diff % mod) % mod;
        }

        return total;
    }
};

int main()
{
    Solution sol;
    int N = 3;
    int K = 2;
    cout << sol.countWays(N, K) << endl;

    N = 2;
    K = 4;
    cout << sol.countWays(N, K) << endl;
    return 0;
}