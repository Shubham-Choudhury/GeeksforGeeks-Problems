// Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;

        vector<int> el = intervals[0];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] > el[1])
            {
                ans.push_back(el);
                el = intervals[i];
            }
            else
            {
                el[1] = max(el[1], intervals[i][1]);
            }
        }
        ans.push_back(el);
        return ans;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    vector<vector<int>> result = object.insertInterval(intervals, newInterval);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    cout << endl;

    intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    newInterval = {4, 9};
    result = object.insertInterval(intervals, newInterval);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    cout << endl;
    return 0;
}