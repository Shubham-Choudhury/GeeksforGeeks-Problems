// Link: https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> leftMin(n, -1), rightMax(n, -1);

        int minIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[minIndex])
            {
                minIndex = i;
            }
            else
            {
                leftMin[i] = minIndex;
            }
        }

        int maxIndex = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[maxIndex])
            {
                maxIndex = i;
            }
            else
            {
                rightMax[i] = maxIndex;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (leftMin[i] != -1 && rightMax[i] != -1)
            {
                return {arr[leftMin[i]], arr[i], arr[rightMax[i]]};
            }
        }

        return {};
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 1, 1, 3};
    vector<int> result = obj.find3Numbers(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    arr = {1, 1, 3};
    result = obj.find3Numbers(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}