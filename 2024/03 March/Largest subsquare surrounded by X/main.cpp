// Link: https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int largestSubsquare(int n, vector<vector<char>> a)
    {
        vector<vector<int>> top(n, vector<int>(n, 0));
        vector<vector<int>> left(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (i != 0)
                        top[i][j] = top[i - 1][j] + 1;
                    else
                        top[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (j != 0)
                        left[i][j] = left[i][j - 1] + 1;
                    else
                        left[i][j] = 1;
                }
            }
        }

        int maxSubSq = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (top[i][j] == 0 || left[i][j] == 0)
                    continue;
                int currentValue = min(top[i][j], left[i][j]);
                int top1 = i - currentValue + 1;
                int left1 = j - currentValue + 1;
                while (currentValue > 0)
                {
                    int top1 = i - currentValue + 1;
                    int left1 = j - currentValue + 1;
                    if ((left[top1][j] >= currentValue) && (top[i][left1] >= currentValue))
                    {
                        maxSubSq = max(maxSubSq, currentValue);
                        break;
                    }
                    currentValue--;
                }
            }
        }
        return maxSubSq;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> a = {{'X', 'X'}, {'X', 'X'}};
    int n = a.size();
    cout << obj.largestSubsquare(n, a) << endl;
    a = {
        {'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'X'},
    };
    n = a.size();
    cout << obj.largestSubsquare(n, a) << endl;
    return 0;
}