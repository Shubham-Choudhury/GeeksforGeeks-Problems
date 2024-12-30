// Link: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRow(int n, int m, vector<vector<int>> a)
    {
        int result = 0;
        int range = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    count++;
                }
            }
            if (range > count)
            {
                range = count;
                result = i;
            }
        }
        return result + 1;
    }
};

int main()
{
    Solution obj;
    int n = 4, m = 4;
    vector<vector<int>> a = {{1, 1, 1, 1},
                             {1, 1, 0, 0},
                             {0, 0, 1, 1},
                             {1, 1, 1, 1}};
    cout << obj.minRow(n, m, a) << endl;

    n = 3, m = 3;
    a = {{0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}};
    cout << obj.minRow(n, m, a) << endl;

    return 0;
}