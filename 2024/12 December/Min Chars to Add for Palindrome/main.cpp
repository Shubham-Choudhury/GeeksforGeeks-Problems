// Link: https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minChar(string &s)
    {
        string rev = s;
        int n = s.length();
        reverse(rev.begin(), rev.end());
        s = s + "#" + rev;
        vector<int> lps(s.length(), 0);
        int l = 0;
        for (int i = 1; i < s.length(); i++)
        {
            while (l > 0 && s[i] != s[l])
            {
                l = lps[l - 1];
            }
            if (s[i] == s[l])
                l++;
            lps[i] = l;
        }

        return n - lps[s.length() - 1];
    }
};

int main()
{
    Solution object;
    string s = "abc";
    cout << object.minChar(s) << endl;
    s = "aacecaaaa";
    cout << object.minChar(s) << endl;
    return 0;
}