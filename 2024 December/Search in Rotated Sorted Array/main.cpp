// Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }
            if (arr[low] <= arr[mid])
            {
                if (key >= arr[low] && key < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (key > arr[mid] && key <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout << object.search(arr, key) << endl;

    arr = {3, 5, 1, 2};
    key = 6;
    cout << object.search(arr, key) << endl;

    arr = {33, 42, 72, 99};
    key = 42;
    cout << object.search(arr, key) << endl;
    return 0;
}