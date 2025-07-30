// Link: https://www.geeksforgeeks.org/problems/powerfull-integer--170647/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int powerfulInteger(vector<vector<int>> &intervals, int k)
    {
        map<int, int> mpp;

        for (auto &x : intervals)
        {
            mpp[x[0]] += 1;
            mpp[x[1] + 1] -= 1;
        }

        int ans = -1;
        int temp = 0;

        for (auto &x : mpp)
        {
            if (mpp[x.first] >= 0)
            {
                temp += mpp[x.first];
                if (temp >= k)
                {
                    ans = x.first;
                }
            }
            else
            {
                if (temp >= k)
                {
                    ans = x.first - 1;
                }
                temp += mpp[x.first];
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {4, 6}, {3, 4}};
    int k = 2;
    int result = sol.powerfulInteger(intervals, k);
    cout << "Powerful Integer: " << result << endl;

    intervals = {{1, 4}, {12, 45}, {3, 8}, {10, 12}};
    k = 3;
    result = sol.powerfulInteger(intervals, k);
    cout << "Powerful Integer: " << result << endl;

    intervals = {{16, 21}, {5, 8}, {12, 17}, {17, 29}, {9, 24}};
    k = 3;
    result = sol.powerfulInteger(intervals, k);
    cout << "Powerful Integer: " << result << endl;
    return 0;
}