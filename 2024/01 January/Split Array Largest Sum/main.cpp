// Link: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(int arr[], int N, int K)
    {
        int totalSum = 0, mx = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            totalSum += arr[i];
            mx = max(mx, arr[i]);
        }

        int lo = mx, hi = totalSum, ans = INT_MAX;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isValid(arr, mid, K, N))
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }

    bool isValid(int arr[], int requiredSum, int k, int n)
    {
        int sum = 0, count = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] <= requiredSum)
            {
                sum += arr[i];
            }
            else
            {
                sum = arr[i];
                count++;
            }
        }
        return count <= k;
    }
};

int main()
{
    Solution obj;
    int N = 4;
    int K = 3;
    int arr[] = {1, 2, 3, 4};
    cout << obj.splitArray(arr, N, K);
    return 0;
}