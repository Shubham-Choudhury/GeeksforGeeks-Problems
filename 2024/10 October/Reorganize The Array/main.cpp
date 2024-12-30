// Link: https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrange(const vector<int> &arr)
    {

        vector<int> ans(arr.size() + 1, -1);
        for (int i = 0; i < arr.size(); i++)
        {
            int elm = arr[i];
            if (elm >= 0)
            {
                ans[elm] = 1;
            }
        }

        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            if (ans[i] == 1)
            {
                result[i] = i;
            }
            else
            {
                result[i] = -1;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vector<int> ans = obj.rearrange(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}