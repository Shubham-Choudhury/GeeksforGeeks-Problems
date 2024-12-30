// Link: https://www.geeksforgeeks.org/problems/smith-number4132/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPrime(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int sod(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int smithNum(int n)
    {
        // code here
        if (isPrime(n))
            return 0;
        int s1 = sod(n);
        int s2 = 0;
        int k = n;
        int i = 2;
        while (k != 1)
        {
            while (k % i == 0)
            {
                s2 += sod(i);
                k /= i;
            }
            i++;
        }
        return s1 == s2;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    cout << obj.smithNum(n) << endl;

    n = 378;
    cout << obj.smithNum(n) << endl;

    return 0;
}