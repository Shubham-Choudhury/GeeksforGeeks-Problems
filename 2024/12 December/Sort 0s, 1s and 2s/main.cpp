// Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int size = arr.size();
        int idx1 = 0, idx2 = size - 1;
        for (int i = 0; i <= idx2; i++)
        {
            if (arr[i] == 0)
            {
                swap(arr[i], arr[idx1]);
                idx1++;
            }
            else if (arr[i] == 2)
            {
                swap(arr[i], arr[idx2]);
                idx2--;
                i--;
            }
        }
    }
};

int main()
{
    Solution object;
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    object.sort012(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    object.sort012(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}