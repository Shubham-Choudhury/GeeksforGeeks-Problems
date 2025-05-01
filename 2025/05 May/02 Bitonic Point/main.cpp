// Link: https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaximum(vector<int> &arr)
    {
        int ans = -1;
        int n = arr.size();
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            {
                ans = arr[mid];
            }
            if (mid > 0 && arr[mid - 1] > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << s.findMaximum(arr) << endl;

    arr = {10, 20, 30, 40, 50};
    cout << s.findMaximum(arr) << endl;

    arr = {120, 100, 80, 20, 0};
    cout << s.findMaximum(arr) << endl;
    return 0;
}