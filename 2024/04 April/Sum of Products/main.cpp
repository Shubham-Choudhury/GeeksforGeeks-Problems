// Link: https://www.geeksforgeeks.org/problems/sum-of-products5049/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        vector<int> cnt(32, 0);
        for (int j = 0; j < 32; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (arr[i] & (1 << j))
                    cnt[j]++;
            }
        }
        long long int ans = 0;
        for (int j = 0; j < 32; j++)
        {
            long long val = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] & (1 << j))
                {
                    cnt[j]--;
                    if (cnt[j] > 0)
                        val += (1LL << j) * cnt[j];
                }
            }
            ans += val;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    long long arr1[] = {5, 10, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.pairAndSum(n1, arr1) << endl;
    long long arr2[] = {10, 20, 30, 40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << obj.pairAndSum(n2, arr2) << endl;
    return 0;
}