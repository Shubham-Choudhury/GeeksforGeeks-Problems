// Link: https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = 0;
        int maxi = 0;
        rightMax[n - 1] = 0;

        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
        }

        maxi = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], arr[i + 1]);
        }

        long long store = 0;
        for (int i = 0; i < n; i++)
        {
            int ans = min(rightMax[i], leftMax[i]);
            if (ans > arr[i])
            {
                store += ans - arr[i];
            }
        }
        return store;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout << object.maxWater(arr) << endl;

    arr = {3, 0, 2, 0, 4};
    cout << object.maxWater(arr) << endl;

    arr = {1, 2, 3, 4};
    cout << object.maxWater(arr) << endl;

    arr = {2, 1, 5, 3, 1, 0, 4};
    cout << object.maxWater(arr) << endl;
    return 0;
}