// Link: https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int j = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    object.pushZerosToEnd(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {10, 20, 30};
    object.pushZerosToEnd(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {0, 0};
    object.pushZerosToEnd(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}