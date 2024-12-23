// Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int row = mat.size();
        int col = mat[0].size();
        int low = 0, high = row * col - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int midVal = mat[mid / col][mid % col];
            if (midVal == x)
            {
                return true;
            }
            else if (midVal < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;
    cout << boolalpha << object.searchMatrix(mat, x) << endl;
    mat = {{1, 5, 9, 11}, {14, 20, 21, 26}, {30, 34, 43, 50}};
    x = 42;
    cout << boolalpha << object.searchMatrix(mat, x) << endl;
    mat = {{87, 96, 99}, {101, 103, 111}};
    x = 101;
    cout << boolalpha << object.searchMatrix(mat, x) << endl;
    return 0;
}