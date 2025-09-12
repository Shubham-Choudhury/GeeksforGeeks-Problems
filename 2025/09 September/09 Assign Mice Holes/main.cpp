// Link: https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int assignHole(vector<int> &mices, vector<int> &holes)
    {
        int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int max = 0;
        for (int i = 0; i < n; ++i)
        {
            if (max < abs(mices[i] - holes[i]))
                max = abs(mices[i] - holes[i]);
        }
        return max;
    }
};

int main()
{
    Solution sol;
    vector<int> mices = {4, -4, 2};
    vector<int> holes = {4, 0, 5};
    int result = sol.assignHole(mices, holes);
    cout << "Minimum time to assign mice to holes: " << result << endl;

    mices = {1, 2};
    holes = {20, 10};
    result = sol.assignHole(mices, holes);
    cout << "Minimum time to assign mice to holes: " << result << endl;
    return 0;
}