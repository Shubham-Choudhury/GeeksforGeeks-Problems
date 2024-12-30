// Link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (2 * i + 1 < n)
            {
                if (arr[i] < arr[2 * i + 1])
                    return (false);
            }
            if (2 * i + 2 < n)
            {
                if (arr[i] < arr[2 * i + 2])
                    return (false);
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;
    int arr[] = {9, 15, 10, 7, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.isMaxHeap(arr, n) << endl;

    int arr1[] = {90, 15, 10, 7, 12, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.isMaxHeap(arr1, n1) << endl;
    return 0;
}