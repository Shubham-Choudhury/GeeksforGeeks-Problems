// Link: https://www.geeksforgeeks.org/problems/two-swaps--155623/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkSorted(vector<int> &arr)
    {
        int n = arr.size();
        int chances = 2;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                swap(arr[i], arr[arr[i] - 1]);
                chances--;
            }
            if (arr[i] != i + 1)
                i--;
            if (chances < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 3, 2, 1};
    cout << obj.checkSorted(arr);
    arr = {4, 3, 1, 2};
    cout << obj.checkSorted(arr);
    return 0;
}