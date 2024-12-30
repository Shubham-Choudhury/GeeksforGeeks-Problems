// Link: https://www.geeksforgeeks.org/problems/next-permutation5226/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();
        int i = n - 2;
        while (i >= 0 && arr[i] >= arr[i + 1])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = n - 1;
            while (arr[j] <= arr[i])
            {
                j--;
            }
            swap(arr[i], arr[j]);
        }

        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    object.nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {3, 2, 1};
    object.nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {3, 4, 2, 5, 1};
    object.nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}