// Link: https://www.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {

        vector<int> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int diff = INT_MAX;
        while (s < e)
        {
            int pairsum = arr[s] + arr[e];
            if (abs(pairsum - target) < diff)
            {
                diff = min(abs(pairsum - target), diff);
                ans = {arr[s], arr[e]};
            }
            if (pairsum < target)
                s++;
            else if (pairsum > target)
                e--;
            else if (pairsum == target)
                return ans;
        }
    }
};

int main()
{
    Solution object;
    vector<int> arr = {10, 30, 20, 5};
    int target = 25;
    vector<int> result = object.sumClosest(arr, target);
    cout << result[0] << " " << result[1] << endl;

    arr = {5, 2, 7, 1, 4};
    target = 10;
    result = object.sumClosest(arr, target);
    cout << result[0] << " " << result[1] << endl;

    arr = {10};
    target = 10;
    result = object.sumClosest(arr, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}