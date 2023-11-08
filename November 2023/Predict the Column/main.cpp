// Link: https://www.geeksforgeeks.org/problems/predict-the-column/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int columnWithMaxZeros(vector<vector<int>> arr, int N)
    {
        int count;
        int idx = -1;
        int prvCount = 0;

        for (int i = 0; i < N; i++)
        {
            count = 0;
            for (int j = 0; j < N; j++)
            {
                if (arr[j][i] == 0)
                {
                    count++;
                }
            }
            if (count > prvCount)
            {
                prvCount = count;
                idx = i;
            }
        }
        return idx;
    }
};

int main()
{
    int N = 3;
    vector<vector<int>> arr = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 0, 0}};
    Solution obj;
    cout << obj.columnWithMaxZeros(arr, N) << endl;
    return 0;
}
