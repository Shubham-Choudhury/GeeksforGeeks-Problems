// Link: https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        int st = 0;
        int end = -1;
        long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < L)
            {
                ans += end - st + 1;
            }
            else if (a[i] <= R)
            {
                end = i;
                ans += (end - st + 1);
            }
            else
            {
                st = i + 1;
                end = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int arr[] = {2, 0, 11, 3, 0};
    int L = 1;
    int R = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.countSubarrays(arr, n, L, R) << endl;
    return 0;
}