// Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumSubstrings(string s)
    {
        long long sum = 0;
        long long position_multiplier = 1;
        long long mod = 1000000007;
        long long result = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            result = (result + (s[i] - '0') * position_multiplier * (i + 1)) % mod;
            position_multiplier = (position_multiplier * 10 + 1) % mod;
        }

        sum = result;
        return sum;
    }
};

int main()
{
    Solution obj;
    string s = "1234";
    cout << obj.sumSubstrings(s) << endl;
    s = "421";
    cout << obj.sumSubstrings(s) << endl;
    return 0;
}