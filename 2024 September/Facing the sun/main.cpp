// Link: https://www.geeksforgeeks.org/problems/facing-the-sun2126/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int countBuildings(vector<int> &height)
    {
        int maxi = INT_MIN;
        int ans = 0;
        for (auto it : height)
        {
            if (maxi < it)
                ans++;
            maxi = max(maxi, it);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> height = {7, 4, 8, 2, 9};
    cout << obj.countBuildings(height) << endl;

    height = {2, 3, 4, 5};
    cout << obj.countBuildings(height) << endl;
    return 0;
}