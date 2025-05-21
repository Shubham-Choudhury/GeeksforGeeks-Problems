// Link: https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPalinSubseq(string &s)
    {
        int n = s.size();
        vector<int> curr(n), prev(n);

        for (int i = n - 1; i >= 0; --i)
        {

            curr[i] = 1;

            for (int j = i + 1; j < n; ++j)
            {

                if (s[i] == s[j])
                {

                    curr[j] = prev[j - 1] + 2;
                }
                else
                {

                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return curr[n - 1];
    }

    int minDeletions(string &s)
    {
        int n = s.length();
        int lps = longestPalinSubseq(s);

        return n - lps;
    }
};

int main()
{
    Solution sol;
    string s = "aebcbda";
    cout << "Minimum deletions to make the string a palindrome: " << sol.minDeletions(s) << endl;

    s = "geeksforgeeks";
    cout << "Minimum deletions to make the string a palindrome: " << sol.minDeletions(s) << endl;
    return 0;
}