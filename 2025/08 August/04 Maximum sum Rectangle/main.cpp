// Link: https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int kadane(vector<int> &temp)
    {
        int rows = temp.size();
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < rows; i++)
        {
            currSum += temp[i];
            if (maxSum < currSum)
            {
                maxSum = currSum;
            }

            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return maxSum;
    }

    int maxRectSum(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        int maxSum = INT_MIN;

        vector<int> temp(rows);

        for (int left = 0; left < cols; left++)
        {
            for (int i = 0; i < rows; i++)
                temp[i] = 0;

            for (int right = left; right < cols; right++)
            {
                for (int row = 0; row < rows; row++)
                {
                    temp[row] += mat[row][right];
                }

                int sum = kadane(temp);

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, -1, -4, -20}, {-8, -3, 4, 2, 1}, {3, 8, 10, 1, 3}, {-4, -1, 1, 7, -6}};
    int result = sol.maxRectSum(mat);
    cout << "Maximum sum rectangle: " << result << endl;

    mat = {{-1, -2}, {-3, -4}};
    result = sol.maxRectSum(mat);
    cout << "Maximum sum rectangle: " << result << endl;

    return 0;
}