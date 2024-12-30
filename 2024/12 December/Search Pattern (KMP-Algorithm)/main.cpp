// Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> search(string &pat, string &txt)
    {
        int m = pat.size();
        vector<int> lps(m, 0);
        int i = 1;
        int prevlps = 0;
        while (i <= m - 1)
        {
            if (pat[prevlps] == pat[i])
            {
                lps[i] = prevlps + 1;
                i++;
                prevlps++;
            }
            else
            {
                if (prevlps == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                    prevlps = lps[prevlps - 1];
            }
        }
        i = 0;
        int j = 0;
        vector<int> ans;
        while (i <= txt.size() - 1)
        {
            if (pat[j] == txt[i])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
            if (j == m)
            {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    string txt = "abcab", pat = "ab";
    vector<int> ans = object.search(pat, txt);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    txt = "abesdu", pat = "edu";
    ans = object.search(pat, txt);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    txt = "aabaacaadaabaaba", pat = "aaba";
    ans = object.search(pat, txt);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}