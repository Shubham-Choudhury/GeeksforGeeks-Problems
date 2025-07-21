// Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i != arr[i - 1])
            {
                return i;
            }
        }

        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    int result = sol.missingNumber(arr);
    cout << "Missing number in [" << [&]()
    {string r; for(int i=0;i<arr.size();++i) r+=to_string(arr[i])+(i<arr.size()-1?", ":""); return r; }() << "] is: " << result << endl;

    arr = {5, 3, 2, 5, 1};
    result = sol.missingNumber(arr);
    cout << "Missing number in [" << [&]()
    {string r; for(int i=0;i<arr.size();++i) r+=to_string(arr[i])+(i<arr.size()-1?", ":""); return r; }() << "] is: " << result << endl;

    arr = {-8, 0, -1, -4, -3};
    result = sol.missingNumber(arr);
    cout << "Missing number in [" << [&]()
    {string r; for(int i=0;i<arr.size();++i) r+=to_string(arr[i])+(i<arr.size()-1?", ":""); return r; }() << "] is: " << result << endl;
    return 0;
}