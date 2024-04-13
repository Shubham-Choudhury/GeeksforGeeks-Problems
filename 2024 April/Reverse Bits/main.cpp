// Link: https://www.geeksforgeeks.org/problems/reverse-bits3556/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long reversedBits(long long x)
    {
        long long ans = 0;
        int pow = 31;
        while (x > 0)
        {
            if (x & 1)
                ans = ans + (1LL << pow);
            x >>= 1;
            pow--;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int x = 1;
    cout << obj.reversedBits(x) << endl;
    x = 5;
    cout << obj.reversedBits(x) << endl;
    return 0;
}