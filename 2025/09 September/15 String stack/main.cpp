// Link: https://www.geeksforgeeks.org/problems/string-stack--165812/1

#include <iostream>
using namespace std;

class Solution
{
public:
    bool stringStack(string &pat, string &tar)
    {
        int i = pat.size() - 1, j = tar.size() - 1;

        while (i >= 0 and j >= 0)
        {
            if (pat[i] != tar[j])
            {
                i -= 2;
            }
            else
            {
                i--;
                j--;
            }
        }
        return j < 0;
    }
};

int main()
{
    Solution sol;
    string pat = "geuaek", tar = "geek";
    bool ans = sol.stringStack(pat, tar);
    cout << "Can the target string " << tar << " be formed from the pattern string " << pat << "? "
         << (ans ? "Yes" : "No") << endl;

    pat = "agiffghd", tar = "gfg";
    ans = sol.stringStack(pat, tar);
    cout << "Can the target string " << tar << " be formed from the pattern string " << pat << "? "
         << (ans ? "Yes" : "No") << endl;

    pat = "ufahs", tar = "aus";
    ans = sol.stringStack(pat, tar);
    cout << "Can the target string " << tar << " be formed from the pattern string " << pat << "? "
         << (ans ? "Yes" : "No") << endl;

    return 0;
}