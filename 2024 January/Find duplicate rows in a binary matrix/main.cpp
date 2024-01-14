// Link: https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
    {
        set<vector<int>> st;
        vector<int> ans;
        int temp = 0;
        for (int i = 0; i < M; i++)
        {
            st.insert(matrix[i]);
            if (st.size() + temp - 1 != i)
            {
                ans.push_back(i);
                temp++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int R = 2;
    int C = 2;
    vector<vector<int>> matrix = {{1, 0},
                                  {1, 0}};
    vector<int> ans = obj.repeatedRows(matrix, R, C);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    R = 4;
    C = 3;
    vector<vector<int>> matrix2 = {{1, 0, 0},
                                   {1, 0, 0},
                                   {0, 0, 0},
                                   {0, 0, 0}};
    ans = obj.repeatedRows(matrix2, R, C);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}