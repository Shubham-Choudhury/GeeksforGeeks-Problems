// Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (mp.find(rem) == mp.end())
                mp[rem] = i;
            else
                ans = max(ans, i - mp[rem]);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 6;
    int K = 3;
    int arr[] = {2, 7, 6, 1, 4, 5};
    cout << obj.longSubarrWthSumDivByK(arr, N, K) << endl;
    N = 7;
    K = 3;
    int arr1[] = {-2, 2, -5, 12, -11, -1, 7};
    cout << obj.longSubarrWthSumDivByK(arr1, N, K) << endl;
    return 0;
}