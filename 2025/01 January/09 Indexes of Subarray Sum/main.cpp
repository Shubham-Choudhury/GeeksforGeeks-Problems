// Link: https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        unordered_map<int, int> getInd;
        int ind = 1;

        int n = arr.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == target)
                return {1, ind};

            int remain = sum - target;

            if (getInd.find(remain) != getInd.end())
            {
                return {getInd[remain] + 1, ind};
            }

            getInd[sum] = ind;
            ind++;
        }

        return {-1};
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = object.subarraySum(arr, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    target = 15;
    result = object.subarraySum(arr, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {5, 3, 4};
    target = 2;
    result = object.subarraySum(arr, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}