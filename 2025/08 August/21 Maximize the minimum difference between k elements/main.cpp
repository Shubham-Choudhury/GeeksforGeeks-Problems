// Link: https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int mid)
    {
        int count = 1;
        int last = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - last >= mid)
            {
                count++;
                last = arr[i];
            }
            if (count == k)
                return true;
        }

        return false;
    }

    int maxMinDiff(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        int low = 0;
        int high = arr.back() - arr.front();
        int answer = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isPossible(arr, k, mid))
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 6, 2, 5};
    int k = 3;
    int result = sol.maxMinDiff(arr, k);
    cout << "Maximum minimum difference between " << k << " elements is: " << result << endl;

    arr = {1, 4, 9, 0, 2, 13, 3};
    k = 4;
    result = sol.maxMinDiff(arr, k);
    cout << "Maximum minimum difference between " << k << " elements is: " << result << endl;
    return 0;
}