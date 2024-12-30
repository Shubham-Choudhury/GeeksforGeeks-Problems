// Link: https://www.geeksforgeeks.org/problems/water-the-plants--170646/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            if (gallery[i] == -1)
                continue;

            v.push_back({max(0, i - gallery[i]), min(n - 1, i + gallery[i])});
        }
        sort(v.begin(), v.end());
        int start = 0;
        int i = 0;
        int ans = 0;
        while (start < n)
        {
            int maxi = INT_MIN;
            while (i < v.size())
            {
                if (v[i].first > start)
                    break;
                maxi = max(maxi, v[i].second);
                i++;
            }
            if (maxi < start)
                return -1;
            ans++;
            start = maxi + 1;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 9;
    int gallery[] = {2, 3, 4, -1, 2, 0, 0, -1, 0};
    cout << obj.min_sprinklers(gallery, n) << endl;
    return 0;
}