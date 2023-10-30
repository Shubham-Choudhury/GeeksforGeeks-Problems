// Link:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        long long int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            long long int unsetBits = 0;
            long long int setBits = 0;
            long long int idSum = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] % 2 == 0)
                    unsetBits++;
                else
                    setBits++;

                arr[j] /= 2;
            }
            idSum = setBits * unsetBits * (1 << i);
            sum += idSum;
        }
        return sum;
    }
};