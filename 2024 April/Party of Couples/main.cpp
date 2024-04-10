// Link: https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSingle(int n, int arr[])
    {
        int single = 0;
        for (int i = 0; i < n; i++)
        {
            single = single ^ arr[i];
        }
        return single;
    }
};

int main()
{
    Solution obj;
    int arr1[] = {1, 2, 3, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.findSingle(n1, arr1) << endl;
    int arr2[] = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << obj.findSingle(n2, arr2) << endl;
    return 0;
}