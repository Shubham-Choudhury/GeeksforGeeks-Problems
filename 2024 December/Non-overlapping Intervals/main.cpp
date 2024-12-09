// Link: https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prevEnd)
            {
                count++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << object.minRemoval(intervals) << endl;

    intervals = {{1, 3}, {1, 3}, {1, 3}};
    cout << object.minRemoval(intervals) << endl;

    intervals = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};
    cout << object.minRemoval(intervals) << endl;

    return 0;
}