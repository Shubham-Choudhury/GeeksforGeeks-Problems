// Link: https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getMinDiff(int k, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minV = arr[0];
        int maxV = arr[n - 1];
        int ans = maxV - minV;
        for (int i = 1; i < n; i++)
        {
            minV = min(arr[0] + k, arr[i] - k);
            maxV = max(arr[n - 1] - k, arr[i - 1] + k);
            ans = min(ans, maxV - minV);
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    cout << object.getMinDiff(k, arr) << endl;

    arr = {3, 9, 12, 16, 20};
    k = 3;
    cout << object.getMinDiff(k, arr) << endl;
    return 0;
}