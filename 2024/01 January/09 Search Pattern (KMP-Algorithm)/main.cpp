// Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        vector<int> indices;
        int n = txt.length();
        int m = pat.length();

        for (int i = 0; i <= n - m; ++i)
        {
            int j;
            for (j = 0; j < m; ++j)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }

            if (j == m)
            {
                indices.push_back(i + 1);
            }
        }
        return indices;
    }
};

int main()
{
    Solution obj;
    string txt = "abesdu";
    string pat = "edu";
    vector<int> ans = obj.search(pat, txt);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    string txt1 = "geeksforgeeks";
    string pat1 = "geek";
    vector<int> ans1 = obj.search(pat1, txt1);
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    return 0;
}