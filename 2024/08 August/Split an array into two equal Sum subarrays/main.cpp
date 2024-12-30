// Link: https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        int totalSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        int temp = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            temp += arr[i];
            totalSum -= arr[i];

            if (temp == totalSum)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 5};
    cout << obj.canSplit(arr) << endl;

    arr = {4, 3, 2, 1};
    cout << obj.canSplit(arr) << endl;
    return 0;
}