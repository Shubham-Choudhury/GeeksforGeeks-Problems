// Link: https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr)
    {
        unordered_set<int> seen;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            if (seen.find(arr[i]) == seen.end())
            {
                ans.push_back(arr[i]);
                seen.insert(arr[i]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 2, 3, 3, 7, 5};
    vector<int> ans = obj.removeDuplicate(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    arr = {2, 2, 5, 5, 7, 7};
    ans = obj.removeDuplicate(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}