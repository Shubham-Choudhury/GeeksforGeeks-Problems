// Link: https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(int *arr, int n)
    {
        int a0 = 0, a1 = arr[0];
        for (int i = 1; i < n; i++)
        {
            int val = max(arr[i] + a0, a1);
            a0 = a1;
            a1 = val;
        }
        return a1;
    }
};

int main()
{
    Solution obj;
    int Arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << obj.findMaxSum(Arr, n) << endl;
}