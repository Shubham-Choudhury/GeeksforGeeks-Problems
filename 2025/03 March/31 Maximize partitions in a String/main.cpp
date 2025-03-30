// Link: https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1

#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxPartitions(string &s)
    {
        int cnt = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]] = i;

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = fmax(ans, mp[s[i]]);

            if (ans == i)
                cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    string s = "acbbcc";
    cout << sol.maxPartitions(s) << endl;

    s = "ababcbacadefegdehijhklij";
    cout << sol.maxPartitions(s) << endl;

    s = "aaa";
    cout << sol.maxPartitions(s) << endl;

    return 0;
}