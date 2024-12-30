// Link: https://www.geeksforgeeks.org/problems/sum-of-prime4751/1

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
private:
    vector<int> allPrime(int N)
    {
        if (N < 2)
        {
            return {};
        }

        vector<bool> prime(N + 1, true);
        prime[0] = prime[1] = false;

        int limit = static_cast<int>(sqrt(N)) + 1;
        for (int p = 2; p <= limit; ++p)
        {
            if (prime[p])
            {
                for (int i = p * p; i <= N; i += p)
                {
                    prime[i] = false;
                }
            }
        }

        vector<int> prime_numbers;
        for (int p = 2; p <= N; ++p)
        {
            if (prime[p])
            {
                prime_numbers.push_back(p);
            }
        }

        return prime_numbers;
    }

public:
    vector<int> getPrimes(int n)
    {
        vector<int> primes = allPrime(n);
        vector<int> ans;
        int left = 0, right = primes.size() - 1;
        while (left <= right)
        {
            if (primes[left] + primes[right] == n)
            {
                ans.push_back(primes[left]);
                ans.push_back(primes[right]);
                return ans;
            }
            else if (primes[left] + primes[right] < n)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans.size() ? ans : vector<int>{-1, -1};
    }
};

int main()
{
    int n = 3;
    Solution obj;
    vector<int> primes = obj.getPrimes(n);
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    n = 10;
    primes = obj.getPrimes(n);
    for (int prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
