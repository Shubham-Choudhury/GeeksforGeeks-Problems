// Link: https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] < v2[0];
    }

    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), compare);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;

        priority_queue<int, vector<int>, greater<int>> unused;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            unused.push(i);
        }

        for (auto x : meetings)
        {
            int s = x[0], e = x[1];

            while (engaged.size() > 0 && engaged.top().first <= s)
            {
                int room = engaged.top().second;
                engaged.pop();

                unused.push(room);
            }

            if (unused.size() > 0)
            {
                int room = unused.top();
                unused.pop();

                freq[abs(room)] += 1;

                engaged.push({e, room});
            }
            else
            {
                pair<long long, int> topmost = engaged.top();
                engaged.pop();

                freq[abs(topmost.second)] += 1;

                long long newEnd = topmost.first;
                newEnd += (e - s);

                engaged.push({newEnd, topmost.second});
            }
        }

        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};

int main()
{
    Solution sol;
    int n = 2;
    vector<vector<int>> meetings = {{0, 6}, {2, 3}, {3, 7}, {4, 8}, {6, 8}};
    cout << "The most booked meeting room is: " << sol.mostBooked(n, meetings) << endl;

    n = 4;
    meetings = {{0, 8}, {1, 4}, {3, 4}, {2, 3}};
    cout << "The most booked meeting room is: " << sol.mostBooked(n, meetings) << endl;
    return 0;
}