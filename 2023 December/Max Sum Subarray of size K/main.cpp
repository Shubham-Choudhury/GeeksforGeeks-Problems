// Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        long i{}, ans{}, sum{};
        for (i = 0; i < K; i++)
            sum += Arr[i];
        ans = max(ans, sum);
        for (i = K; i < N; i++)
        {
            sum += Arr[i];
            sum -= Arr[i - K];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 4, K = 2;
    vector<int> Arr = {100, 200, 300, 400};
    cout << obj.maximumSumSubarray(K, Arr, N) << endl;
    return 0;
}