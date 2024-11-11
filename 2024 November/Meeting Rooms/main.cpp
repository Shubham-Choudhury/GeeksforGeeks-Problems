// Link: https://www.geeksforgeeks.org/problems/attend-all-meetings/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][0] < arr[i - 1][1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> arr = {{1, 4}, {10, 15}, {7, 10}};
    cout << boolalpha << object.canAttend(arr) << endl;

    arr = {{2, 4}, {9, 12}, {6, 10}};
    cout << boolalpha << object.canAttend(arr) << endl;
    return 0;
}