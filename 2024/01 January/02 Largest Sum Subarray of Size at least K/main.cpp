// Link: https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        long long int ans = INT_MIN;
        long long int sum = 0;
        long long int last = 0;
        long long int j = 0;
        for (long long int i = 0; i < n; i++)
        {
            sum += a[i];
            if (i - j + 1 == k)
                ans = max(ans, sum);
            else if (i - j + 1 > k)
            {
                last += a[j];
                j++;
                if (last < 0)
                {
                    sum -= last;
                    last = 0;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    long long int a[] = {-4, -2, 1, -3};
    long long int n = sizeof(a) / sizeof(a[0]);
    long long int k = 2;
    cout << obj.maxSumWithK(a, n, k) << endl;

    return 0;
}