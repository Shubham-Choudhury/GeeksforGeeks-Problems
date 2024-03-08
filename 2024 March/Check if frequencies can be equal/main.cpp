// Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sameFreq(string s)
    {
        int dist_chars = 0, minfreq = INT_MAX, maxfreq = INT_MIN;
        int min_chars = 0, max_chars = 0;
        map<char, int> mp;

        for (auto i : s)
        {
            mp[i]++;
        }

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            minfreq = min(minfreq, i->second);
            maxfreq = max(maxfreq, i->second);
        }

        dist_chars = mp.size();
        if (minfreq == maxfreq)
        {
            return true;
        }

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i->second == minfreq)
            {
                min_chars++;
            }
            if (i->second == maxfreq)
            {
                max_chars++;
            }
        }

        if (maxfreq == s.length())
        {
            return true;
        }

        if (dist_chars != min_chars + max_chars)
        {
            return false;
        }

        if (minfreq == 1 && min_chars == 1)
        {
            return true;
        }

        if (minfreq != maxfreq - 1)
        {
            return false;
        }

        if (max_chars > 1 && min_chars >= 1)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution obj;
    string s = "xyyz";
    cout << obj.sameFreq(s) << endl;
    s = "xxxxyyzz";
    cout << obj.sameFreq(s) << endl;
    s="xxyyz";
    cout << obj.sameFreq(s) << endl;
    return 0;
}