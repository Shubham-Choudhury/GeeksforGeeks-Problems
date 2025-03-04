// Link: https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lis(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n + 2), curr(n + 2);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                int take = -1e8;
                int notTake = prev[j];
                if (j - 1 == n)
                {
                    take = 1 + prev[i];
                }
                else if (arr[i - 1] < arr[j - 1])
                {
                    take = 1 + prev[i];
                }
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n + 1];
    }
};

int main()
{
    Solution object;
    vector<int> arr = {5, 8, 3, 7, 9, 1};
    cout << object.lis(arr) << endl;

    arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << object.lis(arr) << endl;

    arr = {3, 10, 2, 1, 20};
    cout << object.lis(arr) << endl;
    return 0;
}