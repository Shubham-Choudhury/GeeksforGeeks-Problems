// Link: https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> primeFactors(int num)
    {
        vector<vector<int>> factors;

        int count = 0;
        while (num % 2 == 0)
        {
            num /= 2;
            count++;
        }
        if (count > 0)
            factors.push_back({2, count});

        for (int i = 3; i * i <= num; i += 2)
        {
            count = 0;
            while (num % i == 0)
            {
                num /= i;
                count++;
            }
            if (count > 0)
                factors.push_back({i, count});
        }

        if (num > 1)
            factors.push_back({num, 1});

        return factors;
    }

    int legendre(int n, int p)
    {
        int count = 0;
        for (int power = p; power <= n; power *= p)
        {
            count += n / power;
        }
        return count;
    }

    int maxKPower(int n, int k)
    {

        vector<vector<int>> factors = primeFactors(k);

        int result = INT_MAX;

        for (auto &factor : factors)
        {
            int prime = factor[0];
            int expInK = factor[1];

            int countInFact = legendre(n, prime);

            result = min(result, countInFact / expInK);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n = 7;
    int k = 2;
    int result = sol.maxKPower(n, k);
    cout << "Maximum power of " << k << " in " << n << "! is " << result << endl;

    n = 10;
    k = 9;
    result = sol.maxKPower(n, k);
    cout << "Maximum power of " << k << " in " << n << "! is " << result << endl;

    return 0;
}