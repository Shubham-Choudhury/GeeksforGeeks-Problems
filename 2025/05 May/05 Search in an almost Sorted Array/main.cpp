// Link: https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findTarget(vector<int> &arr, int target)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            if (mid - 1 >= s && arr[mid - 1] == target)
            {
                return mid - 1;
            }
            if (mid + 1 <= e && arr[mid + 1] == target)
            {
                return mid + 1;
            }
            if (target < arr[mid])
            {
                e = mid - 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 40;
    int result = obj.findTarget(arr, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    arr = {10, 3, 40, 20, 50, 80, 70};
    target = 90;
    result = obj.findTarget(arr, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    arr = {-20};
    target = -20;
    result = obj.findTarget(arr, target);
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}