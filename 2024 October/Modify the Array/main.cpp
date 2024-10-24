// Link: https://www.geeksforgeeks.org/problems/ease-the-array0633/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void shiftZeroes(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (arr[i] != 0)
                swap(arr[i], arr[j++]);
        }
    }

    vector<int> modifyAndRearrangeArray(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1] && arr[i] != 0)
            {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }
        shiftZeroes(arr);
        return arr;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 2, 0, 4, 0, 8};
    vector<int> res = obj.modifyAndRearrangeArray(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    arr = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
    res = obj.modifyAndRearrangeArray(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}