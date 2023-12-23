// Link: https://www.geeksforgeeks.org/problems/count-element-occurences/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOccurence(int arr[], int n, int k)
    {
        // Your code here
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        int r = n / k;
        int ans = 0;
        for (auto it : m)
        {
            if (it.second > r)
                ans++;
        }
        return ans;
    }
};

int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    Solution s;
    cout << s.countOccurence(arr, n, k);
    return 0;
}