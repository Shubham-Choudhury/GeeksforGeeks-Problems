// Link: https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubSeq(string &s1, string &s2)
    {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }

        return i == n;
    }
};

int main()
{
    Solution sol;
    string s1 = "AXY";
    string s2 = "YADXCP";
    bool result = sol.isSubSeq(s1, s2);
    cout << "Is \"" << s1 << "\" a subsequence of \"" << s2 << "\"? " << (result ? "YES" : "NO") << endl;

    s1 = "gksrek";
    s2 = "geeksforgeeks";
    result = sol.isSubSeq(s1, s2);
    cout << "Is \"" << s1 << "\" a subsequence of \"" << s2 << "\"? " << (result ? "YES" : "NO") << endl;
    return 0;
}