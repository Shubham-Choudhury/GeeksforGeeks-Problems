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
        int i = 0;
        if (n == 1)
        {
            return 0;
        }
        if (arr[i] == 0)
        {
            return -1;
        }
        int jumps = 1;
        int maxReach = arr[0];
        int steps = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0)
            {
                jumps++;
                if (i >= maxReach)
                    return -1;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << obj.minJumps(arr) << endl;

    arr = {1, 4, 3, 2, 6, 7};
    cout << obj.minJumps(arr) << endl;

    arr = {0, 10, 20};
    cout << obj.minJumps(arr) << endl;
    return 0;
}