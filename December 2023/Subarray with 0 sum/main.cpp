// Link: https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int i, sum = 0;
        mp[0] = 1;
        for (i = 0; i < n; i++)
        {
            sum += arr[i];
            if (mp.find(sum) != mp.end())
                return 1;
            mp[sum]++;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.subArrayExists(arr, n) << endl;

    int arr1[] = {4, 2, 0, 1, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.subArrayExists(arr1, n1) << endl;

    return 0;
}