// Link: https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] - mid - 1 < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low + k;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << object.kthMissing(arr, k) << endl;

    arr = {1, 2, 3};
    k = 2;
    cout << object.kthMissing(arr, k) << endl;

    arr = {3, 5, 9, 10, 11, 12};
    k = 2;
    cout << object.kthMissing(arr, k) << endl;
    return 0;
}