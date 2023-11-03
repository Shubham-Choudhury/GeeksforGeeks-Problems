// Link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        int ans[n];
        for (int i = 0; i < n; i++)
        {
            ans[i] = arr[i] * arr[i];
        }
        sort(ans, ans + n);
        for (int i = n - 1; i > 1; i--)
        {
            int ele = i;
            int l = 0;
            int r = i - 1;
            while (l < r)
            {
                if (ans[l] + ans[r] == ans[ele])
                    return true;
                else if (ans[l] + ans[r] > ans[ele])
                    r--;
                else
                    l++;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int arr[] = {3, 2, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.checkTriplet(arr, n);
    return 0;
}