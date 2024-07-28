// Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        int max_row_index = -1;
        int j = m - 1;

        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && arr[i][j] == 1)
            {
                j--;
                max_row_index = i;
            }
        }

        return max_row_index;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << obj.rowWithMax1s(arr) << endl;

    arr = {{0, 0}, {1, 1}};
    cout << obj.rowWithMax1s(arr) << endl;

    return 0;
}