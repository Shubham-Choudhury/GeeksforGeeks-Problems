// Link: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int nthStair(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        int f[n];
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                f[i] = f[i - 2] + 1;
            }
            else
            {
                f[i] = f[i - 1];
            }
        }
        return f[n];
    }
};

int main()
{
    Solution obj;
    int n = 4;
    cout << obj.nthStair(n) << endl;
    n = 5;
    cout << obj.nthStair(n) << endl;
    return 0;
}