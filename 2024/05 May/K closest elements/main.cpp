// Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int findCrossOver(vector<int> &arr, int low, int high, int x)
    {
        if (arr[high] <= x)
            return high;
        if (arr[low] > x)
            return low;

        int mid = (low + high) / 2;

        if (arr[mid] <= x && arr[mid + 1] > x)
            return mid;

        if (arr[mid] < x)
            return findCrossOver(arr, mid + 1, high, x);

        return findCrossOver(arr, low, mid - 1, x);
    }

public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        vector<int> v;
        if (n == 0)
            return v;

        int l = findCrossOver(arr, 0, n - 1, x);
        int r = l + 1;
        int count = 0;
        if (arr[l] == x)
            l--;

        while (l >= 0 && r < n && count < k)
        {
            if (x - arr[l] < arr[r] - x)
                v.push_back(arr[l--]);
            else
                v.push_back(arr[r++]);
            count++;
        }

        while (count < k && l >= 0)
        {
            v.push_back(arr[l--]);
            count++;
        }
        while (count < k && r < n)
        {
            v.push_back(arr[r++]);
            count++;
        }

        return v;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 16, 22, 30, 35, 39, 42,
                       45, 48, 50, 53, 55, 56};
    int n = arr.size();
    int k = 4, x = 35;
    vector<int> ans = obj.printKClosest(arr, n, k, x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    arr = {1, 2, 3, 6, 10};
    n = arr.size();
    k = 3, x = 4;
    ans = obj.printKClosest(arr, n, k, x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}