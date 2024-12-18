// Link: https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mat[3][3], res[3][3];

    void mul(long long res[3][3], long long mat[3][3], long long m)
    {
        long long res1[3][3];
        memset(res1, 0, sizeof(res1));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    res1[i][j] += (res[i][k] * mat[k][j]);
                    res1[i][j] %= m;
                }
            }
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                res[i][j] = res1[i][j];
    }

    void mat_exp(long long n, long long m)
    {
        while (n > 0)
        {
            if (n & 1)
                mul(res, mat, m);
            mul(mat, mat, m);
            n /= 2;
        }
    }

    long long genFibNum(long long a, long long b, long long c, long long n, long long m)
    {
        memset(res, 0, sizeof(res));
        res[0][0] = res[1][1] = res[2][2] = 1;
        mat[0][0] = a;
        mat[0][1] = b;
        mat[0][2] = mat[1][0] = mat[2][2] = 1;
        mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
        if (n <= 2)
            return (1 % m);
        else
        {
            mat_exp(n - 2, m);
            return (res[0][0] + res[0][1] + c * res[0][2]) % m;
        }
    }
};

int main()
{
    Solution obj;
    int a = 3;
    int b = 3;
    int c = 3;
    int n = 3;
    int m = 5;
    cout << obj.genFibNum(a, b, c, n, m) << endl;
    a = 2;
    b = 2;
    c = 2;
    n = 4;
    m = 100;
    cout << obj.genFibNum(a, b, c, n, m) << endl;
    return 0;
}
