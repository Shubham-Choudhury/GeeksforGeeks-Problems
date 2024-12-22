// Link: https://www.geeksforgeeks.org/problems/search-in-a-row-wise-sorted-matrix/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool searchRowMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            if (x >= mat[i][0] && x <= mat[i][m - 1])
            {
                bool result = binary_search(mat[i].begin(), mat[i].end(), x);
                if (result)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat{{3, 4, 9}, {2, 5, 6}, {9, 25, 27}};
    int x = 9;
    cout << boolalpha << object.searchRowMatrix(mat, x) << endl;
    mat = {{19, 22, 27, 38, 55, 67}};
    x = 56;
    cout << boolalpha << object.searchRowMatrix(mat, x) << endl;
    mat = {{1, 2, 9}, {65, 69, 75}};
    x = 91;
    cout << boolalpha << object.searchRowMatrix(mat, x) << endl;
}