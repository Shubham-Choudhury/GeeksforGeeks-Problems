// Link: https://www.geeksforgeeks.org/problems/ncr1019/1

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;

        if (r == 0 || n == r)
            return 1;

        double res = 0;

        for (int i = 0; i < r; i++)
        {
            res += log(n - i) - log(i + 1);
        }
        return (int)round(exp(res));
    }
};

int main()
{
    Solution obj;
    int n = 5, r = 2;
    cout << "nCr(" << n << ", " << r << ") = " << obj.nCr(n, r) << endl;
    n = 2, r = 4;
    cout << "nCr(" << n << ", " << r << ") = " << obj.nCr(n, r) << endl;
    n = 5, r = 0;
    cout << "nCr(" << n << ", " << r << ") = " << obj.nCr(n, r) << endl;

    return 0;
}