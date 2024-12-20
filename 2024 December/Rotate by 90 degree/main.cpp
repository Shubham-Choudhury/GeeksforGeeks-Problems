// Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotateby90(vector<vector<int>> &mat)
    {
        for (int i = 0; i < mat.size() - 1; i++)
        {
            for (int j = i + 1; j < mat.size(); j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        reverse(mat.begin(), mat.end());
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    object.rotateby90(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    mat = {{1, 2},
           {3, 4}};
    object.rotateby90(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}