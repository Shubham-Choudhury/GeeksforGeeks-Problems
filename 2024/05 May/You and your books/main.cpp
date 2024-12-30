// Link: https://www.geeksforgeeks.org/problems/you-and-your-books/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long max_Books(int arr[], int n, int k)
    {
        long long ans = 0, curr = 0;
        int i = 0;
        while (i < n)
        {
            if (arr[i] <= k)
            {
                curr += arr[i];
            }
            else
            {
                curr = 0;
            }

            ans = max(ans, curr);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int arr1[] = {3, 2, 2, 3, 1, 1, 1, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 1;
    cout << obj.max_Books(arr1, n, k) << endl;

    int arr2[] = {3, 2, 2, 3, 1, 1, 1, 3};
    n = sizeof(arr2) / sizeof(arr2[0]);
    k = 2;
    cout << obj.max_Books(arr2, n, k) << endl;

    return 0;
}