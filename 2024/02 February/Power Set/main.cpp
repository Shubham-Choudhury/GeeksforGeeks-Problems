// Link: https://www.geeksforgeeks.org/problems/power-set4302/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {

        vector<string> ans;
        int n = s.size();
        int power = pow(2, n);

        for (int i = 1; i < power; i++)
        {
            string k;
            int num = i;
            int j = 0;
            while (num != 0)
            {
                int a = (num & 1);
                if (a)
                    k.push_back(s[j]);
                j++;
                num = num >> 1;
            }
            ans.push_back(k);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "abc";
    vector<string> ans = obj.AllPossibleStrings(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    s = "aa";
    ans = obj.AllPossibleStrings(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}