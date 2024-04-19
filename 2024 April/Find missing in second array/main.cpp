// Link: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        vector<int> result;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[b[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                result.push_back(a[i]);
            }
        }
        return result;
    }
};