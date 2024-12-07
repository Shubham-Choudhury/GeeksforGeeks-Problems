// Link: https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        for (auto interval : arr)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> result = object.mergeOverlap(arr);
    for (auto interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << endl;

    arr = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    result = object.mergeOverlap(arr);
    for (auto interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
    cout << endl;
    return 0;
}