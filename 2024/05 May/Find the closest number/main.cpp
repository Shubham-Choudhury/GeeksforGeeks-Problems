// Link: https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == k)
                return k;
            else if (arr[mid] < k)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if (abs(arr[start] - k) < abs(arr[end] - k))
        {
            return arr[start];
        }
        else if (abs(arr[start] - k) > abs(arr[end] - k))
        {
            return arr[end];
        }
        else
        {
            return max(arr[start], arr[end]);
        }
    }
};

int main()
{
    Solution obj;
    int arr1[] = {1, 3, 6, 7};
    int n = sizeof(arr1) / sizeof(int);
    int k = 4;
    cout << obj.findClosest(n, k, arr1) << endl;

    int arr2[] = {1, 2, 3, 5, 6, 8, 9};
    n = sizeof(arr2) / sizeof(int);
    k = 4;
    cout << obj.findClosest(n, k, arr2) << endl;

    return 0;
}