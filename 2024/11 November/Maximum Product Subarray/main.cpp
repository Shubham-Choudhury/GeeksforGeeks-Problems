// Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        int p = 1, s = 1, ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (p == 0)
            {
                p = 1;
            }
            if (s == 0)
            {
                s = 1;
            }
            p *= arr[i];
            s *= arr[n - i - 1];

            ans = max(ans, max(p, s));
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << object.maxProduct(arr) << endl;

    arr = {-1, -3, -10, 0, 60};
    cout << object.maxProduct(arr) << endl;

    arr = {2, 3, 4};
    cout << object.maxProduct(arr) << endl;
    return 0;
}