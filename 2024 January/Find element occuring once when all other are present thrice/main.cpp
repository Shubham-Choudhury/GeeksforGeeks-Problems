// Link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleElement(int arr[], int N)
    {
        sort(arr, arr + N);
        for (int i = 0; i < N - 2;)
        {
            if (arr[i] != arr[i + 2])
            {
                return arr[i];
            }
            i = i + 3;
        }
        return arr[N - 1];
    }
};

int main()
{
    Solution obj;
    int arr[] = {1, 10, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << obj.singleElement(arr, n);
    return 0;
}