// Link: https://www.geeksforgeeks.org/problems/how-many-xs4514/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int countX(int L, int R, int X)
    {
        // code here
        int ans = 0;
        while (++L < R)
        {
            int val = L;
            while (val)
            {
                if (val % 10 == X)
                    ans++;
                val /= 10;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int L = 10;
    int R = 19;
    int X = 1;
    cout << obj.countX(L, R, X) << endl;
    return 0;
}