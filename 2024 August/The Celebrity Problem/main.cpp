// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int potential_celebrity = 0;

        for (int i = 1; i < n; ++i)
        {
            if (mat[potential_celebrity][i] == 1)
            {
                potential_celebrity = i;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (i != potential_celebrity)
            {
                if (mat[potential_celebrity][i] == 1 || mat[i][potential_celebrity] == 0)
                {
                    return -1;
                }
            }
        }

        return potential_celebrity;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << obj.celebrity(mat) << endl;
    mat = {{0, 1}, {1, 0}};
    cout << obj.celebrity(mat) << endl;
    return 0;
}
