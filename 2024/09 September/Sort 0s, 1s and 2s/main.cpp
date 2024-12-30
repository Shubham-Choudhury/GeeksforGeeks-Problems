// Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sort012(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else if (arr[mid] == 2)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {0, 2, 1, 2, 0};
    obj.sort012(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {0, 1, 0};
    obj.sort012(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}