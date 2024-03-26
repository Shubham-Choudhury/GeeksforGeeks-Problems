// Link: https://www.geeksforgeeks.org/problems/additive-sequence/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &s, int ind, int n, bool &l)
    {
        if (ind >= n)
        {
            l = 1;
            return;
        }
        int numi = 0;
        for (int i = ind; i < n; i++)
        {
            numi = numi * 10 + (s[i] - '0');
            int numj = 0;
            for (int j = i + 1; j < n; j++)
            {
                numj = numj * 10 + (s[j] - '0');
                string temp = to_string(numi + numj);
                int tn = temp.size();
                if (tn <= n - j - 1)
                {
                    bool t = 1;
                    for (int k = 0; k < tn; k++)
                    {
                        if (temp[k] != s[j + k + 1])
                            t = 0;
                    }
                    if (t)
                        solve(s, j + tn + 1, n, l);
                }
                if (l)
                    return;
            }
        }
    }
    bool isAdditiveSequence(string n)
    {
        bool l = 0;
        solve(n, 0, n.size(), l);
        return l;
    }
};

int main()
{
    Solution obj;
    string n = "1235813";
    cout << obj.isAdditiveSequence(n) << endl;
    n = "11235815";
    cout << obj.isAdditiveSequence(n) << endl;
    return 0;
}