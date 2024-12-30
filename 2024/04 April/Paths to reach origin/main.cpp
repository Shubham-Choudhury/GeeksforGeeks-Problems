// Link: https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[500][500];
    int solveUsingRe(int x, int y)
    {
        if (x == 0 && y == 0)
            return 1;
        int incx = 0;
        int incy = 0;
        if (t[x][y] != -1)
            return t[x][y];
        if (x)
        {
            incx = solveUsingRe(x - 1, y);
        }
        if (y)
            incy = solveUsingRe(x, y - 1);

        return t[x][y] = (incx + incy) % 1000000007;
    }
    int ways(int x, int y)
    {
        memset(t, -1, sizeof(t));
        return solveUsingRe(x, y) % 1000000007;
    }
};

int main()
{
    Solution obj;
    int x = 3, y = 0;
    cout << obj.ways(x, y) << endl;
    x = 3, y = 6;
    cout << obj.ways(x, y) << endl;
    return 0;
}