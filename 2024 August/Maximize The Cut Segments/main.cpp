// Link: https://www.geeksforgeeks.org/problems/cutted-segments1642/1

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int cut[3];
        cut[0] = x;
        cut[1] = y;
        cut[2] = z;
        int t[4][n + 1];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = INT_MIN;
                }
                if (j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < n + 1; j++)

            {
                if (cut[i - 1] <= j)
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - cut[i - 1]] + 1);
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        if (t[3][n] < 0)
        {
            return 0;
        }
        return t[3][n];
    }
};

int main()
{
    Solution obj;
    int n = 5;
    int x = 5;
    int y = 3;
    int z = 2;

    cout << obj.maximizeTheCuts(n, x, y, z) << endl;

    n = 4;
    x = 2;
    y = 1;
    z = 1;
    cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    return 0;
}