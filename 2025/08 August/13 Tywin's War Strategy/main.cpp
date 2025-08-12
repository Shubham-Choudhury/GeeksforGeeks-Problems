// Link: https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSoldiers(vector<int> &arr, int k)
    {
        int n = arr.size();
        int need = (n + 1) / 2;
        vector<int> costs;

        for (int num : arr)
        {
            if (num % k == 0)
            {
                costs.push_back(0);
            }
            else
            {
                costs.push_back(k - (num % k));
            }
        }

        sort(costs.begin(), costs.end());

        int total = 0;
        for (int i = 0; i < need; ++i)
        {
            total += costs[i];
        }

        return total;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 6, 3, 2, 1};
    int k = 2;
    int result = sol.minSoldiers(arr, k);
    cout << result << endl;

    arr = {3, 5, 6, 7, 9, 10};
    k = 4;
    result = sol.minSoldiers(arr, k);
    cout << result << endl;
    return 0;
}