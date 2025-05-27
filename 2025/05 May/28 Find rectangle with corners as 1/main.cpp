// Link: https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool ValidCorner(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        if (rows == 0)
            return false;
        int columns = mat[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int p = i + 1; p < rows; p++)
            {
                int count = 0;

                for (int k = 0; k < columns; k++)
                {
                    if (mat[i][k] == 1 && mat[p][k] == 1)
                    {
                        count++;
                    }
                }
                if (count >= 2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 0, 0, 1, 0},
                               {0, 0, 1, 0, 1},
                               {0, 0, 0, 1, 0},
                               {1, 0, 1, 0, 1}};

    if (obj.ValidCorner(mat))
    {
        cout << "Yes, rectangle with corners as 1 exists." << endl;
    }
    else
    {
        cout << "No, rectangle with corners as 1 does not exist." << endl;
    }

    mat = {{1, 1, 1, 1},
           {1, 0, 0, 1},
           {1, 0, 0, 1},
           {1, 1, 1, 1}};
    if (obj.ValidCorner(mat))
    {
        cout << "Yes, rectangle with corners as 1 exists." << endl;
    }
    else
    {
        cout << "No, rectangle with corners as 1 does not exist." << endl;
    }

    mat = {{1, 0, 0, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 1}};
    if (obj.ValidCorner(mat))
    {
        cout << "Yes, rectangle with corners as 1 exists." << endl;
    }
    else
    {
        cout << "No, rectangle with corners as 1 does not exist." << endl;
    }

    return 0;
}