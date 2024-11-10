// Link: https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minIncrements(vector<int> arr)
    {
        int n = arr.size();
        long long diff = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                arr[i + 1]++;
                diff++;
            }
            if (arr[i] > arr[i + 1])
            {
                diff = diff + (arr[i] - arr[i + 1]) + 1;
                arr[i + 1] = arr[i] + 1;
            }
        }
        return diff;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 2};
    cout << object.minIncrements(arr) << endl;

    arr = {1, 1, 2, 3};
    cout << object.minIncrements(arr) << endl;

    arr = {5, 4, 3, 2, 1};
    cout << object.minIncrements(arr) << endl;
    return 0;
}