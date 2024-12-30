// Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pairWithMaxSum(vector<int> &arr)
    {
        if (arr.size() < 2)
            return -1;
        int res = arr[0] + arr[1];
        for (size_t i = 1; i < arr.size() - 1; ++i)
            res = max(res, arr[i] + arr[i + 1]);
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 3, 1, 5, 6};
    cout << obj.pairWithMaxSum(arr) << endl;

    arr = {1};
    cout << obj.pairWithMaxSum(arr) << endl;
    return 0;
}