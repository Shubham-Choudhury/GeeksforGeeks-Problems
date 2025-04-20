// Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        int n = arr.size(), res = n + 1;
        for (int i = 0; i < n; i++)
        {
            res += (i + 1) - arr[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 5};
    cout << "Missing number is: " << sol.missingNum(arr) << endl;

    arr = {8, 2, 4, 5, 3, 7, 1};
    cout << "Missing number is: " << sol.missingNum(arr) << endl;

    arr = {1};
    cout << "Missing number is: " << sol.missingNum(arr) << endl;
    return 0;
}