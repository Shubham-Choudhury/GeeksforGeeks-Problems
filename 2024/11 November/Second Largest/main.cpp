// Link: https://www.geeksforgeeks.org/problems/second-largest3735/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int maxi = *max_element(arr.begin(), arr.end());
        int ans = -1;
        for (auto it : arr)
        {
            if (it < maxi)
            {
                ans = max(ans, it);
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << object.getSecondLargest(arr) << endl;

    arr = {10, 5, 10};
    cout << object.getSecondLargest(arr) << endl;

    arr = {10, 10, 10};
    cout << object.getSecondLargest(arr) << endl;
    return 0;
}