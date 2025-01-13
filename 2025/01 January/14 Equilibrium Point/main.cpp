// Link: https://www.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        int prefixsum = 0;
        for (auto i : arr)
            prefixsum += i;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            prefixsum -= arr[i];
            if (prefixsum == sum)
                return i;
            sum += arr[i];
        }
        return -1;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 0, 3};
    cout << object.findEquilibrium(arr) << endl;

    arr = {1, 1, 1, 1};
    cout << object.findEquilibrium(arr) << endl;

    arr = {-7, 1, 5, 2, -4, 3, 0};
    cout << object.findEquilibrium(arr) << endl;
    return 0;
}