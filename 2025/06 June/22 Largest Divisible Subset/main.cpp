// Link: https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lds(vector<int> &arr, vector<int> &memo, vector<int> &parent, int i)
    {
        if (memo[i] != -1)
        {
            return memo[i];
        }

        int maxLength = 1;
        int bestParent = -1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] % arr[i] == 0)
            {
                int length = lds(arr, memo, parent, j) + 1;
                if (length > maxLength)
                {
                    maxLength = length;
                    bestParent = j;
                }
            }
        }

        memo[i] = maxLength;
        parent[i] = bestParent;
        return maxLength;
    }

    vector<int> largestSubset(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.rbegin(), arr.rend());

        vector<int> memo(n, -1);
        vector<int> parent(n, -1);
        int maxSize = 0;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            int size = lds(arr, memo, parent, i);
            if (size > maxSize)
            {
                maxSize = size;
                lastIndex = i;
            }
        }

        vector<int> res;
        for (int i = lastIndex; i >= 0; i = parent[i])
        {
            res.push_back(arr[i]);
            if (parent[i] == -1)
                break;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 16, 7, 8, 4};
    vector<int> result = sol.largestSubset(arr);

    cout << "Largest Divisible Subset: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    arr = {2, 4, 3, 8};
    result = sol.largestSubset(arr);
    cout << "Largest Divisible Subset: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}