// Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int top = 0, left = 0, bottom = mat.size() - 1, right = mat[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            int i = top, j = left;
            while (j <= right)
            {
                ans.push_back(mat[i][j]);
                j++;
            }
            j--;
            i++;
            while (i <= bottom)
            {
                ans.push_back(mat[i][j]);
                i++;
            }
            top++;
            right--;
            i = bottom;
            j = right;
            if (top > bottom || left > right)
            {
                return ans;
            }
            while (j >= left)
            {
                ans.push_back(mat[i][j]);
                j--;
            }
            j = left;
            i--;
            while (i >= top)
            {
                ans.push_back(mat[i][j]);
                i--;
            }
            left++;
            bottom--;
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> ans = object.spirallyTraverse(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    mat = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};
    ans = object.spirallyTraverse(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    mat = {{32, 44, 27, 23}, {54, 28, 50, 62}};
    ans = object.spirallyTraverse(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}