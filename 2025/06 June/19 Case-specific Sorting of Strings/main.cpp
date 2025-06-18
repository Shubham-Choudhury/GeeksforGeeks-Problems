// Link: https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string caseSort(string &s)
    {
        int n = s.length();
        int lower[26] = {0}, upper[26] = {0};
        for (char ch : s)
        {
            if (islower(ch))
            {
                lower[ch - 'a']++;
            }
            else
            {
                upper[ch - 'A']++;
            }
        }

        string result = s;
        int l = 0, u = 0;

        for (int i = 0; i < n; i++)
        {
            if (islower(s[i]))
            {
                while (lower[l] == 0)
                {
                    l++;
                }
                result[i] = 'a' + l;
                lower[l]--;
            }
            else
            {
                while (upper[u] == 0)
                {
                    u++;
                }
                result[i] = 'A' + u;
                upper[u]--;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "GEekS";
    cout << sol.caseSort(s) << endl;

    s = "XWMSPQ";
    cout << sol.caseSort(s) << endl;
    return 0;
}