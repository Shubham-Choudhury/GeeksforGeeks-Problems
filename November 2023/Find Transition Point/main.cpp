// Link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    int arr[] = {0, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.transitionPoint(arr, n) << endl;

    return 0;
}