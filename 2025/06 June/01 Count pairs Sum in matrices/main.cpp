// Link: https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x)
    {
        int r1 = 0, c1 = 0;
        int r2 = mat2.size() - 1, c2 = mat2[0].size() - 1;

        int count = 0;

        while (r1 < mat1.size() && r2 >= 0)
        {
            int val = mat1[r1][c1] + mat2[r2][c2];

            if (val == x)
            {
                count++;

                c1++;
                c2--;
            }
            else if (val < x)
            {
                c1++;
            }
            else
            {
                c2--;
            }

            if (c1 == mat1[0].size())
            {
                c1 = 0;
                r1++;
            }

            if (c2 == -1)
            {
                c2 = mat2[0].size() - 1;
                r2--;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat1 = {{1, 5, 6}, {8, 10, 11}, {15, 16, 18}};
    vector<vector<int>> mat2 = {{2, 4, 7}, {9, 10, 12}, {13, 16, 20}};
    int x = 21;
    int result = obj.countPairs(mat1, mat2, x);
    cout << "Count of pairs with sum " << x << " is: " << result << endl;

    mat1 = {{1, 2}, {3, 4}};
    mat2 = {{4, 5}, {6, 7}};
    x = 10;
    result = obj.countPairs(mat1, mat2, x);
    cout << "Count of pairs with sum " << x << " is: " << result << endl;
    return 0;
}