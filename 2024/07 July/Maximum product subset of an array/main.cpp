// Link: https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long int findMaxProduct(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        long long n = arr.size();
        long long zero = 0, neg = 0, pos = 0;

        long long ans = 1;

        for (auto val : arr)
        {
            if (val > 0)
            {
                ans = (ans * val) % mod;
            }
            if (val == 0)
                zero++;
            else if (val < 0)
                neg++;
            else
                pos++;
        }

        if (neg / 2)
        {
            int finalVal = neg % 2;
            for (auto val : arr)
            {
                if (val < 0 && neg > finalVal)
                {
                    ans = (ans * val + mod) % mod;
                    neg--;
                }
            }
        }

        if (pos == 0 && ans == 1)
        {
            if (zero)
                ans = 0;
            else
                ans = *max_element(arr.begin(), arr.end());
        }
        return (ans + mod) % mod;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-1, 0, -2, 4, 3};
    cout << obj.findMaxProduct(arr) << endl;

    arr = {-1, 0};
    cout << obj.findMaxProduct(arr) << endl;

    arr = {5};
    cout << obj.findMaxProduct(arr) << endl;
    return 0;
}