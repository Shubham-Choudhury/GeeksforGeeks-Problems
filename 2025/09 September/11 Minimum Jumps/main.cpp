// Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (arr[0] == 0)
            return -1;

        int maxReach = 0;
        int currReach = 0;
        int jump = 0;

        for (int i = 0; i < n; i++)
        {
            maxReach = max(maxReach, i + arr[i]);
            if (maxReach >= n - 1)
            {
                return jump + 1;
            }

            if (i == currReach)
            {
                if (i == maxReach)
                {
                    return -1;
                }
                else
                {
                    jump++;
                    currReach = maxReach;
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int result = sol.minJumps(arr);
    cout << "Minimum number of jumps: " << result << endl;

    arr = {1, 4, 3, 2, 6, 7};
    result = sol.minJumps(arr);
    cout << "Minimum number of jumps: " << result << endl;

    arr = {0, 10, 20};
    result = sol.minJumps(arr);
    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}