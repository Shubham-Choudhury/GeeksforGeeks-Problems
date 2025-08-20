// Link: https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int row = mid / m;
            int col = mid % m;
            int midVal = mat[row][col];

            if (midVal == x)
            {
                return true;
            }

            int lowRow = low / m;
            int lowCol = low % m;
            int lowVal = mat[lowRow][lowCol];

            if (lowVal <= midVal)
            {
                if (lowVal <= x && x < midVal)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                int highRow = high / m;
                int highCol = high % m;
                int highVal = mat[highRow][highCol];

                if (midVal < x && x <= highVal)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {{7, 8, 9, 10}, {11, 12, 13, 1}, {2, 3, 4, 5}};
    int x = 3;
    int result = sol.searchMatrix(mat, x);
    cout << "Element " << x << " found in matrix: " << (result ? "true" : "false") << endl;

    mat = {{6, 7, 8}, {9, 1, 2}, {3, 4, 5}};
    x = 10;
    result = sol.searchMatrix(mat, x);
    cout << "Element " << x << " found in matrix: " << (result ? "true" : "false") << endl;

    return 0;
}