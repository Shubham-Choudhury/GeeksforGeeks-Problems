// Link: https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long max_sum(int a[], int n)
    {
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            res += (1ll * i * a[i]);
        }
        long long ans = res;
        for (int i = 0; i < n - 1; i++)
        {
            long long temp = sum - a[i];
            res = res - temp + (1ll * (n - 1) * a[i]);
            ans = max(ans, res);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int a1[] = {8, 3, 1, 2};
    int n = sizeof(a1) / sizeof(int);
    cout << obj.max_sum(a1, n) << endl;

    int a2[] = {1, 2, 3};
    n = sizeof(a2) / sizeof(int);
    cout << obj.max_sum(a2, n) << endl;

    return 0;
}
