// Link: https://www.geeksforgeeks.org/problems/summed-matrix5834/1

#include <iostream>
using namespace std;

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        if (q == 1 || q > 2 * n)
            return 0;
        return (q <= n + 1) ? q - 1 : 2 * n - q + 1;
    }
};

int main()
{
    Solution obj;
    int n = 4, q = 7;
    cout << obj.sumMatrix(n, q) << endl;

    n = 5, q = 4;
    cout << obj.sumMatrix(n, q) << endl;

    return 0;
}