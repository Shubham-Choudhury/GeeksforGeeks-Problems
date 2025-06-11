// Link: https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int k, int x)
    {
        int n = arr.size();
        int i = 0;

        int low = 0, high = n - 1, pos = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] < x)
            {
                pos = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        int left = pos, right = pos + 1;

        if (arr[right] == x)
            right++;

        vector<int> res;

        while (left >= 0 && right < n && res.size() < k)
        {
            int leftDiff = abs(arr[left] - x);
            int rightDiff = abs(arr[right] - x);

            if (leftDiff < rightDiff)
            {
                res.push_back(arr[left]);
                left--;
            }
            else
            {
                res.push_back(arr[right]);
                right++;
            }
        }

        while (left >= 0 && res.size() < k)
        {
            res.push_back(arr[left]);
            left--;
        }

        while (right < n && res.size() < k)
        {
            res.push_back(arr[right]);
            right++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 4, 10, 12};
    int k = 2, x = 4;
    vector<int> result = sol.printKClosest(arr, k, x);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    k = 4, x = 35;
    result = sol.printKClosest(arr, k, x);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}