// Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxMeetings(int n, int start[], int end[])
    {
        vector<pair<int, int>> meetings(n);

        for (int i = 0; i < n; ++i)
        {
            meetings[i] = {end[i], start[i]};
        }

        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEndTime = 0;

        for (const auto &meeting : meetings)
        {
            if (meeting.second > lastEndTime)
            {
                ++count;
                lastEndTime = meeting.first;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    cout << obj.maxMeetings(n, start, end) << endl;
    return 0;
}