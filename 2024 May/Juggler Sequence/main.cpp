// Link: https://www.geeksforgeeks.org/problems/juggler-sequence3930/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> jugglerSequence(int n)
    {
        vector<int> ans;
        ans.push_back(n);

        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n = pow(n, 0.5);
            }
            else
            {
                n = pow(n, 1.5);
            }
            ans.push_back(n);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int n = 9;
    vector<int> ans = obj.jugglerSequence(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    n = 6;
    ans = obj.jugglerSequence(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}