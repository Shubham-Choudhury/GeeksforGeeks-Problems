// Link: https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int ans = 0;

        for (int num : left)
        {
            ans = max(ans, num);
        }

        for (int num : right)
        {
            ans = max(ans, n - num);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0, 1, 3};
    int result = sol.getLastMoment(n, left, right);
    cout << "Last moment before all ants fall out: " << result << endl;

    n = 4;
    left = {};
    right = {0, 1, 2, 3, 4};
    result = sol.getLastMoment(n, left, right);
    cout << "Last moment before all ants fall out: " << result << endl;

    n = 3;
    left = {0};
    right = {3};
    result = sol.getLastMoment(n, left, right);
    cout << "Last moment before all ants fall out: " << result << endl;

    return 0;
}