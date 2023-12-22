// Link: https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool custom(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
    {
        if (a.first.second != b.first.second)
        {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<pair<pair<int, int>, int>> v;
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            v.push_back({{S[i], F[i]}, i + 1});
        }
        sort(v.begin(), v.end(), custom);
        ans.push_back(v[0].second);
        int prev = v[0].first.second;
        for (int i = 0; i < N; i++)
        {
            if (v[i].first.first > prev)
            {
                ans.push_back(v[i].second);
                prev = v[i].first.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};
    vector<int> ans = obj.maxMeetings(N, S, F);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}