// Link: https://www.geeksforgeeks.org/problems/print-pattern3549/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    vector<int> pattern(int N)
    {
        // code here
        vector<int> ans = {N};
        int n = N;
        while (N > 0)
        {
            ans.push_back(N -= 5);
        }
        while (N < n)
        {
            ans.push_back(N += 5);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 10;
    vector<int> ans = obj.pattern(N);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}