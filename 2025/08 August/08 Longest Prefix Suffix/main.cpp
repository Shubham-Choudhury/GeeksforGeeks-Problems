// Link: https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getLPSLength(string &s)
    {
        int n = s.size();

        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (s[i] == s[len])
            {
                lps[i] = ++len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];
    }
};

int main()
{
    Solution sol;
    string s = "abab";
    int result = sol.getLPSLength(s);
    cout << "The length of the longest prefix which is also a suffix for '" << s << "' is: " << result << endl;

    s = "aabcdaabc";
    result = sol.getLPSLength(s);
    cout << "The length of the longest prefix which is also a suffix for '" << s << "' is: " << result << endl;

    s = "aaaa";
    result = sol.getLPSLength(s);
    cout << "The length of the longest prefix which is also a suffix for '" << s << "' is: " << result << endl;

    return 0;
}