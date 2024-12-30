// Link: https://www.geeksforgeeks.org/problems/need-some-change/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swapElements(int arr[], int n)
    {
        for (int i = 0; i < n - 2; i++)
        {
            swap(arr[i], arr[i + 2]);
        }
    }
};

int main()
{
    Solution obj;
    int ar[] = {1, 2, 3};
    int n = sizeof(ar) / sizeof(ar[0]);
    obj.swapElements(ar, n);
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    int arr[] = {1, 2, 3, 4, 5};
    n = sizeof(arr) / sizeof(arr[0]);
    obj.swapElements(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}