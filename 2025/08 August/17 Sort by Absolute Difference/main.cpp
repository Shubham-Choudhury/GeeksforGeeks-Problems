// Link: https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rearrange(vector<int> &arr, int x)
    {

        int n = arr.size();

        stable_sort(arr.begin(), arr.end(), [x](int a, int b)
                    {
            if (abs(a - x) < abs(b - x))
                return true;
            else
                return false; });
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 5, 3, 9, 2};
    int x = 7;
    sol.rearrange(arr, x);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    arr = {1, 2, 3, 4, 5};
    x = 6;
    sol.rearrange(arr, x);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}