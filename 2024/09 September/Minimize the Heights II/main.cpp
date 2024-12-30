// Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int max_diff = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 1; i < n; i++)
        {
            int min_value = min(smallest, arr[i] - k);
            int max_value = max(largest, arr[i - 1] + k);
            if (min_value < 0)
            {
                continue;
            }
            max_diff = min(max_diff, max_value - min_value);
        }

        return max_diff;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 5, 8, 10};
    int k1 = 2;
    cout << obj.getMinDiff(arr1, k1) << endl;

    vector<int> arr2 = {3, 9, 12, 16, 20};
    int k2 = 3;
    cout << obj.getMinDiff(arr2, k2) << endl;

    return 0;
}
