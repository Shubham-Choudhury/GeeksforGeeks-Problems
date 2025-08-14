// Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    vector<vector<int>> result = sol.insertInterval(intervals, newInterval);
    for (auto &r : result)
    {
        cout << "[" << r[0] << ", " << r[1] << "] ";
    }
    cout << "\n";

    intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    newInterval = {4, 9};
    result = sol.insertInterval(intervals, newInterval);
    for (auto &r : result)
    {
        cout << "[" << r[0] << ", " << r[1] << "] ";
    }
    cout << "\n";

    return 0;
}