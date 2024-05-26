// Link: https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinCost(string x, string y, int costX, int costY)
    {
        int m = x.length(), n = y.length();
        vector<int> prv(m + 1, 0);
        vector<int> cur(m + 1, 0);
        for (int b = 1; b <= n; b++)
        {
            for (int a = 1; a <= m; a++)
            {
                if (x[a - 1] == y[b - 1])
                {
                    cur[a] = prv[a - 1] + 1;
                }
                cur[a] = max(cur[a], max(prv[a], cur[a - 1]));
            }
            prv = cur;
        }
        int mx = cur[m];
        return (m - mx) * costX + (n - mx) * costY;
    }
};

int main()
{
    Solution obj;
    string x = "ef";
    string y = "gh";
    int costX = 10;
    int costY = 20;
    cout << obj.findMinCost(x, y, costX, costY) << endl;

    x = "abcd";
    y = "acdb";
    costX = 10;
    costY = 20;
    cout << obj.findMinCost(x, y, costX, costY) << endl;
    return 0;
}
