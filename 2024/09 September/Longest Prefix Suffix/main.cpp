// Link: https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lps(string str)
    {
        vector<int> lps(str.size(), 0);
        int prefix = 0, suffix = 1;

        while (suffix < lps.size())
        {
            if (str[prefix] == str[suffix])
            {
                lps[suffix] = prefix + 1;
                prefix++, suffix++;
            }
            else
            {
                if (prefix == 0)
                {
                    lps[suffix] = 0;
                    suffix++;
                }
                else
                {
                    prefix = lps[prefix - 1];
                }
            }
        }
        return lps[lps.size() - 1];
    }
};

int main()
{
    Solution obj;
    string str = "abab";
    cout << obj.lps(str) << endl;

    str = "aaaa";
    cout << obj.lps(str) << endl;
    return 0;
}