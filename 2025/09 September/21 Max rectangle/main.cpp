// Link: https://www.geeksforgeeks.org/problems/max-rectangle/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int getMaxArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                int tp = s.top();
                s.pop();

                int width = s.empty() ? i : i - s.top() - 1;

                res = max(res, heights[tp] * width);
            }
            s.push(i);
        }

        while (!s.empty())
        {
            int tp = s.top();
            s.pop();

            int width = s.empty() ? n : n - s.top() - 1;
            res = max(res, heights[tp] * width);
        }

        return res;
    }

    int maxArea(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();

        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 1)
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, getMaxArea(heights));
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{0, 1, 1, 0},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 0, 0}};
    int result = obj.maxArea(mat);
    cout << "Maximum rectangle area is: " << result << endl;

    mat = {{0, 1, 1},
           {1, 1, 1},
           {0, 1, 1}};
    result = obj.maxArea(mat);
    cout << "Maximum rectangle area is: " << result << endl;
    return 0;
}