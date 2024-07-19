// Link: https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> constructLowerArray(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        if (n == 0)
            return ans;

        vector<int> sorted;

        sorted.push_back(arr[n - 1]);
        ans.push_back(0);

        for (int i = n - 2; i >= 0; i--)
        {
            auto it = lower_bound(sorted.begin(), sorted.end(), arr[i]);

            ans.push_back(it - sorted.begin());

            sorted.insert(it, arr[i]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 1, 2, 3, 0, 11, 4};
    vector<int> ans = obj.constructLowerArray(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    arr = {1, 2, 3, 4, 5};
    ans = obj.constructLowerArray(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}