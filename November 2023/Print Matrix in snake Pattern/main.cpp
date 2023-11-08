// Link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> snakePattern(vector<vector<int>> &matrix)
    {
        int flag = 0;
        vector<int> ans;
        for (auto i : matrix)
        {
            if (flag % 2 == 0)
            {
                ans.insert(ans.end(), i.begin(), i.end());
            }
            else
            {
                reverse(i.begin(), i.end());
                ans.insert(ans.end(), i.begin(), i.end());
            }
            flag += 1;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{45, 48, 54}, {21, 89, 87}, {70, 78, 15}};
    vector<int> ans = obj.snakePattern(matrix);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
