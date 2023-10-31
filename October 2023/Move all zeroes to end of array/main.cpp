// Link: https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(
                    arr[i],
                    arr[j]);
                    j++;
            }
        }
    }
};

int main(){
    Solution obj;
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.pushZerosToEnd(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}