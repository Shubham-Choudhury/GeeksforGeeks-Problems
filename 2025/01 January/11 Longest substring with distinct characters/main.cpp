// Link: https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        unordered_map<char, int> mp;
        int start = 0, n = s.length(), maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start)
                start = mp[s[i]] + 1;
            mp[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution object;
    string s = "geeksforgeeks";
    cout << object.longestUniqueSubstr(s) << endl;

    s = "aaa";
    cout << object.longestUniqueSubstr(s) << endl;

    s = "abcdefabcbb";
    cout << object.longestUniqueSubstr(s) << endl;
    return 0;
}