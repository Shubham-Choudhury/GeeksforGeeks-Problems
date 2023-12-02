// Link: https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for (int i = N - 1; i > 0; i--)
            if (arr[i] <= arr[i - 1])
                return 0;
        return 1;
    }
};

int main()
{
    Solution obj;
    int N = 3;
    int arr[N] = {2, 4, 5};
    cout << obj.isRepresentingBST(arr, N);
    return 0;
}