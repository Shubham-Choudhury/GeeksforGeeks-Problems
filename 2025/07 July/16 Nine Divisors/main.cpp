// Link: https://www.geeksforgeeks.org/problems/nine-divisors3751/1

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int countNumbers(int n)
    {
        int c = 0;
        int limit = sqrt(n);

        int prime[limit + 1];
        for (int i = 1; i <= limit; i++)
            prime[i] = i;

        for (int i = 2; i * i <= limit; i++)
        {
            if (prime[i] == i)
            {
                for (int j = i * i; j <= limit; j += i)
                    if (prime[j] == j)
                        prime[j] = i;
            }
        }

        for (int i = 2; i <= limit; i++)
        {
            int p = prime[i];
            int q = prime[i / prime[i]];

            if (p * q == i && q != 1 && p != q)
            {
                c += 1;
            }
            else if (prime[i] == i && pow(i, 8) <= n)
            {
                c += 1;
            }
        }

        return c;
    }
};

int main()
{
    Solution sol;
    int n = 100;
    int result = sol.countNumbers(n);
    cout << "Count of numbers with exactly nine divisors up to " << n << " is: " << result << endl;

    n = 200;
    result = sol.countNumbers(n);
    cout << "Count of numbers with exactly nine divisors up to " << n << " is: " << result << endl;

    return 0;
}