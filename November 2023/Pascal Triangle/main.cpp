// Link: https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> nthRowOfPascalTriangle(int n)
    {
        // code here
        long long mod = 1000000007;
        vector<long long> al(n, 0);

        al[0] = 1;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                al[j] = (al[j] % mod + al[j - 1] % mod) % mod;
            }
        }
        return al;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    vector<long long> ans = obj.nthRowOfPascalTriangle(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    n = 5;
    ans = obj.nthRowOfPascalTriangle(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}