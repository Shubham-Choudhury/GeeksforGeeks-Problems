// Link: https://www.geeksforgeeks.org/problems/castle-run3644/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPossible(vector<vector<int>> paths)
    {
        int n = paths.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (paths[i][j] == 1)
                    cnt++;
            }
            if (cnt % 2 != 0)
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> paths = {{0, 1, 1, 1, 1},
                                 {1, 0, 0, 1, 0},
                                 {1, 0, 0, 1, 0},
                                 {1, 1, 1, 0, 1},
                                 {1, 0, 0, 1, 0}};
    cout << obj.isPossible(paths) << endl;

    paths = {{0, 1, 1, 0},
             {1, 0, 1, 1},
             {1, 1, 0, 0},
             {0, 1, 0, 0}};
    cout << obj.isPossible(paths) << endl;
    return 0;
}