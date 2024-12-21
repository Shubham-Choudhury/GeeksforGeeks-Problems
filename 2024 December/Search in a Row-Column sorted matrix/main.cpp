// Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool matSearch(vector<vector<int>> &mat, int x)
    {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int h = m - 1;
        while (l < n && h >= 0)
        {
            if (mat[l][h] == x)
            {
                return true;
            }
            else if (mat[l][h] < x)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> mat = {{3, 30, 38}, {20, 52, 54}, {35, 60, 69}};
    int x = 62;
    cout << boolalpha << object.matSearch(mat, x) << endl;

    mat = {{18, 21, 27}, {38, 55, 67}};
    x = 55;
    cout << boolalpha << object.matSearch(mat, x) << endl;

    mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    x = 3;
    cout << boolalpha << object.matSearch(mat, x) << endl;
    return 0;
}