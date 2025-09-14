// Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int totalGas = 0;
        int currGas = 0;
        int startIdx = 0;

        for (int i = 0; i < n; i++)
        {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];

            if (currGas < 0)
            {
                currGas = 0;
                startIdx = i + 1;
            }
        }

        if (totalGas < 0)
            return -1;

        return startIdx;
    }
};

int main()
{
    Solution sol;
    vector<int> gas = {4, 5, 7, 4};
    vector<int> cost = {6, 6, 3, 5};
    int result = sol.startStation(gas, cost);
    cout << "Starting gas station index: " << result << endl;

    gas = {3, 9};
    cost = {7, 6};
    result = sol.startStation(gas, cost);
    cout << "Starting gas station index: " << result << endl;
    return 0;
}