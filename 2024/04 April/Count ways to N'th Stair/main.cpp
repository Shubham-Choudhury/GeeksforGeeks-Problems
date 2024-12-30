// Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int n)
    {
        long long y = 0;
        long long cnt = 0;
        while (n - 2 * y >= 0)
        {
            cnt++;
            y++;
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    cout << obj.countWays(n) << endl;
    n = 5;
    cout << obj.countWays(n) << endl;
    return 0;
}