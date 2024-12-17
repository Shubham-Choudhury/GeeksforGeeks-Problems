// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &arr, int n, int m, int maxAllowed)
    {
        int s = 1, p = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxAllowed)
                return false;
            if (p + arr[i] <= maxAllowed)
            {
                p += arr[i];
            }
            else
            {
                s++;
                p = arr[i];
            }
        }
        return s <= m;
    }

    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int ans = -1, st = 0, end = sum;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (isValid(arr, n, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << object.findPages(arr, k) << endl;

    arr = {15, 17, 20};
    k = 5;
    cout << object.findPages(arr, k) << endl;

    arr = {22, 23, 67};
    k = 1;
    cout << object.findPages(arr, k) << endl;
    return 0;
}