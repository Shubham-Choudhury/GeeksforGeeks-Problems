// Link: https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        map<int, vector<int>> m;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                m[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> v;
        int k = 0;
        for (auto i : m)
        {
            if (k % 2 == 0 and k > 0)
            {
                reverse(i.second.begin(), i.second.end());
            }

            for (auto ele : i.second)
            {
                v.push_back(ele);
            }

            k++;
        }
        return v;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    vector<int> ans = obj.matrixDiagonally(mat);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    mat = {{1, 2},
           {3, 4}};
    ans = obj.matrixDiagonally(mat);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}