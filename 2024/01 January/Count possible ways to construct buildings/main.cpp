// Link: https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int TotalWays(int N)
    {
        int mod = 1e9 + 7;
        long long prev1 = 1, prev2 = 1;
        for (int i = 1; i <= N; i++)
        {
            long long curr = (prev1 + prev2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return (prev1 * prev1) % mod;
    }
};

int main()
{
    Solution obj;
    int N = 1;
    cout << obj.TotalWays(N) << endl;
    N = 3;
    cout << obj.TotalWays(N) << endl;
    return 0;
}