// Link: https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    bool isPal(vector<int> &arr)
    {
        vector<int> v(arr.begin(), arr.end());
        reverse(v.begin(), v.end());
        return v == arr;
    }

public:
    string pattern(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        string ansRow = "";
        string ansCol = "-1";
        for (int i = 0; i < n; i++)
        {
            if (isPal(arr[i]))
            {
                ansRow += to_string(i) + " R";
                return ansRow;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (isPal(arr[i]))
            {
                ansCol = to_string(i) + " C";
                break;
            }
        }
        return ansCol;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> arr = {{1, 0, 0}, {0, 1, 0}, {1, 1, 0}};
    cout << obj.pattern(arr) << endl;

    arr = {{1, 0}};
    cout << obj.pattern(arr) << endl;
    return 0;
}