// Link: https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if (m == n)
        {
            return -1;
        }
        if (n > m)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        int res = 0;
        while (m > 0)
        {
            res++;
            int d1 = m % 2;
            int d2 = n % 2;
            if (d1 != d2)
            {
                return res;
            }
            m = m / 2;
            n = n / 2;
        }
    }
};

int main()
{
    int M = 11;
    int N = 9;
    Solution obj;
    cout << obj.posOfRightMostDiffBit(M, N) << endl;
    return 0;
}