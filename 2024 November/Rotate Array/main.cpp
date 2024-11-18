// Link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotateArr(vector<int> &arr, int d)
    {
        int n = arr.size();
        d = d % n;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + arr.size() - d);
        reverse(arr.begin() + arr.size() - d, arr.end());
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;
    object.rotateArr(arr, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    d = 3;
    object.rotateArr(arr, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {7, 3, 9, 1};
    d = 9;
    object.rotateArr(arr, d);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}