// Link: https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumBitDifferences(int arr[], int n)
    {
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            long long a = 0, b = 0;
            for (int j = 0; j < n; j++)
            {
                int k = (arr[j] >> i);
                if (k & 1)
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            ans += (a * b);
        }
        return 2LL * ans;
    }
};

int main()
{
    Solution obj;
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.sumBitDifferences(arr, n) << endl;
    return 0;
}