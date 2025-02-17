// Link: https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {12, 5, 787, 1, 23};
    int k = 2;
    vector<int> result = object.kLargest(arr, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {1, 23, 12, 9, 30, 2, 50};
    k = 3;
    result = object.kLargest(arr, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {12, 23};
    k = 1;
    result = object.kLargest(arr, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}