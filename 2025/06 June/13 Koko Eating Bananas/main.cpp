// Link: https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &arr, int mid, int k)
    {
        int hours = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            hours += arr[i] / mid;
            if (arr[i] % mid != 0)
            {
                hours++;
            }
        }
        return hours <= k;
    }

    int kokoEat(vector<int> &arr, int k)
    {
        int lo = 1;

        int hi = *max_element(arr.begin(), arr.end());
        int res = hi;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (check(arr, mid, k) == true)
            {
                hi = mid - 1;
                res = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 6, 7, 11};
    int k = 8;
    cout << "Minimum eating speed: " << sol.kokoEat(arr, k) << endl;

    arr = {30, 11, 23, 4, 20};
    k = 5;
    cout << "Minimum eating speed: " << sol.kokoEat(arr, k) << endl;

    arr = {5, 10, 15, 20};
    k = 7;
    cout << "Minimum eating speed: " << sol.kokoEat(arr, k) << endl;
    return 0;
}