// Link: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        int check = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            check += (gas[i] - cost[i]);
        }
        if (check < 0)
        {
            return -1;
        }
        int index = 0;
        int store = 0;
        for (int i = 0; i < n; i++)
        {
            store += (gas[i] - cost[i]);
            if (store < 0)
            {
                index = i + 1;
                store = 0;
            }
        }
        return index;
    }
};

int main()
{
    Solution obj;
    vector<int> gas = {4, 5, 7, 4};
    vector<int> cost = {6, 6, 3, 5};
    int result = obj.startStation(gas, cost);
    cout << "Starting station index: " << result << endl;

    gas = {1, 2, 3, 4, 5};
    cost = {3, 4, 5, 1, 2};
    result = obj.startStation(gas, cost);
    cout << "Starting station index: " << result << endl;

    gas = {3, 9};
    cost = {7, 6};
    result = obj.startStation(gas, cost);
    cout << "Starting station index: " << result << endl;
    return 0;
}