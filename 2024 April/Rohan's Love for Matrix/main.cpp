// Link: https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstElement(int n)
    {
        int mod = 1000000007;
        if (n == 1)
            return 1;
        else if (n == 2)
            return 1;

        int a = 1;
        int b = 1;

        for (int i = 3; i <= n - 1; i++)
        {

            int t = b;

            b = (a + b) % mod;
            a = t;
        }

        return (a + b) % mod;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    cout << obj.firstElement(n) << endl;

    n = 4;
    cout << obj.firstElement(n) << endl;
    return 0;
}