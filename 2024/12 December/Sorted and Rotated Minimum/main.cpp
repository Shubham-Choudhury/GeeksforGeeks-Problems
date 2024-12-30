// Link: https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int mini = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            mini = min(mini, arr[i]);
        }
        return mini;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << object.findMin(arr) << endl;
    arr = {3, 2, 2, 2};
    cout << object.findMin(arr) << endl;
    arr = {4, 4, 4};
    cout << object.findMin(arr) << endl;
    return 0;
}