// Link: https://www.geeksforgeeks.org/problems/peak-element/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (m < n - 1)
            {
                if (arr[m] < arr[m + 1])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else
            {
                break;
            }
        }
        return l;
    }
};

int main()
{
    Solution obj;
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.peakElement(arr, n) << endl;
    return 0;
}