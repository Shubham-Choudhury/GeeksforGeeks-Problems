// Link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        vector<int> v;
        int n = S.size();
        string ans;
        for (int i = 0; i <= n; i++)
        {
            v.push_back(i + 1);
        }
        for (int i = 0; i < n; i++)
        {
            int temp = i;
            while (temp != n && S[temp] == 'D')
            {
                temp++;
            }
            reverse(v.begin() + i, v.begin() + temp + 1);
            if (temp != i)
            {
                i = temp - 1;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            ans += v[i] + '0';
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string S;
    S = "D";
    cout << obj.printMinNumberForPattern(S) << endl;
    S = "IDD";
    cout << obj.printMinNumberForPattern(S) << endl;
    return 0;
}