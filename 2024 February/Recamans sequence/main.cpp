// Link: https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        vector<int> ans(n, 0);
        unordered_set<int> s;
        s.insert(0);
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] - i;
            if (ans[i] <= 0 || s.find(ans[i]) != s.end())
                ans[i] = ans[i - 1] + i;
            s.insert(ans[i]);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n;
    n = 5;
    vector<int> ans = obj.recamanSequence(n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    n = 3;
    ans = obj.recamanSequence(n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}