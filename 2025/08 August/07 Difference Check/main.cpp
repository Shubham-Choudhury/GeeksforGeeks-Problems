// Link: https://www.geeksforgeeks.org/problems/difference-check/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int toSeconds(string &time)
    {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int minDifference(vector<string> &arr)
    {
        int totalSec = 24 * 3600;
        vector<bool> seen(totalSec, false);

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int sec = toSeconds(arr[i]);
            if (seen[sec])
            {
                return 0;
            }
            seen[sec] = true;
        }

        int first = -1;
        int last = -1;
        int prev = -1;
        int minDiff = INT_MAX;

        for (int i = 0; i < totalSec; i++)
        {
            if (!seen[i])
                continue;

            if (prev != -1)
            {
                minDiff = min(minDiff, i - prev);
            }
            else
            {
                first = i;
            }

            prev = i;
            last = i;
        }

        int wrap = first + totalSec - last;
        minDiff = min(minDiff, wrap);

        return minDiff;
    }
};

int main()
{
    Solution sol;
    vector<string> arr = {"12:30:15", "12:30:45"};
    int result = sol.minDifference(arr);
    cout << "Minimum difference: " << result << " seconds" << endl;

    arr = {"00:00:01", "23:59:59", "00:00:05"};
    result = sol.minDifference(arr);
    cout << "Minimum difference: " << result << " seconds" << endl;
    return 0;
}