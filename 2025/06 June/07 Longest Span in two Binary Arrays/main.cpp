// Link: https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int res = 0;

        unordered_map<int, int> diffMap;

        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++)
        {
            sum1 += arr1[i];
            sum2 += arr2[i];

            int currentDiff = sum1 - sum2;
            if (currentDiff == 0)
            {
                res = max(res, i + 1);
            }

            else if (diffMap.find(currentDiff) != diffMap.end())
            {
                res = max(res, i - diffMap[currentDiff]);
            }
            else
            {

                diffMap[currentDiff] = i;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1 = {0, 1, 0, 1, 1};
    vector<int> arr2 = {1, 0, 1, 0, 1};

    int result = solution.longestCommonSum(arr1, arr2);
    cout << "Longest span with same sum in two binary arrays: " << result << endl;

    return 0;
}