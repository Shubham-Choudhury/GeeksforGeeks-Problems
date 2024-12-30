// Link: https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findSplit(vector<int> &arr)
    {
        int sum = 0;
        for (auto i : arr)
        {
            sum += i;
        }
        if (sum % 3 != 0)
        {
            return {-1, -1};
        }
        vector<int> ans(2);
        int part = sum / 3;
        int n = arr.size();
        int i = 0;
        sum = 0;
        int cnt = 0;
        while (i < n)
        {
            sum += arr[i];
            if (sum == part && cnt < 2)
            {
                ans.push_back(i);
                cnt++;
                sum = 0;
            }
            i++;
        }
        if (sum != part || cnt != 2)
        {
            return {-1, -1};
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 3, 4, 0, 4};
    vector<int> ans = object.findSplit(arr);
    if (ans[0] == -1 && ans[1] == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }

    arr = {2, 3, 4};
    ans = object.findSplit(arr);
    if (ans[0] == -1 && ans[1] == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }

    arr = {0, 1, 1};
    ans = object.findSplit(arr);
    if (ans[0] == -1 && ans[1] == -1)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }

    return 0;
}