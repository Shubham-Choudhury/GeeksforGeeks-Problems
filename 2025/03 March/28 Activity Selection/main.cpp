// Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        vector<pair<int, int>> activities;

        for (size_t i = 0; i < start.size(); i++)
        {
            activities.push_back({start[i], finish[i]});
        }

        sort(activities.begin(), activities.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int count = 1;
        int lastFinishTime = activities[0].second;

        for (size_t i = 1; i < activities.size(); i++)
        {
            if (activities[i].first > lastFinishTime)
            {
                count++;
                lastFinishTime = activities[i].second;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int result = obj.activitySelection(start, end);
    cout << "Maximum number of activities: " << result << endl;

    start = {10, 12, 20};
    end = {20, 25, 30};
    result = obj.activitySelection(start, end);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}