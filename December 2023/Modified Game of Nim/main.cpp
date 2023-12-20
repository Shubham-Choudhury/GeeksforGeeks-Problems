// Link: https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWinner(int n, int A[])
    {

        int xorr = 0;
        for (int i = 0; i < n; i++)
            xorr ^= A[i];

        if (!xorr)
            return 1;
        else
            return (n % 2) + 1;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    int A[] = {1, 2, 3};
    cout << obj.findWinner(n, A) << endl;
    return 0;
}