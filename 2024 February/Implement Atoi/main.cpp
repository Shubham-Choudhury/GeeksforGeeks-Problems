// Link: https://www.geeksforgeeks.org/problems/implement-atoi/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atoi(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((i == 0) && (s[i] == '-'))
            {
                continue;
            }
            else if (s[i] - '0' > 9 || s[i] - '0' < 0)
            {
                return -1;
            }
            ans = 10 * ans + (s[i] - '0');
        }
        if (s[0] == '-')
        {
            return -ans;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "-123";
    cout << obj.atoi(s) << endl;
    s = "21a";
    cout << obj.atoi(s) << endl;
    return 0;
}