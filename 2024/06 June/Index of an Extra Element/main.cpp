// Link: https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int findExtra(int n, int arr1[], int arr[])
    {
        int low = 0;
        int high = n - 2;
        int index = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr1[mid] == arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                index = mid;
                high = mid - 1;
            }
        }
        return index;
    }
};

int main()
{
    Solution obj;
    int a1[] = {2, 4, 6, 8, 9, 10, 12};
    int b1[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(a1) / sizeof(int);
    cout << obj.findExtra(n, a1, b1) << endl;

    int a2[] = {3, 5, 7, 8, 11, 13};
    int b2[] = {3, 5, 7, 11, 13};
    n = sizeof(a2) / sizeof(int);
    cout << obj.findExtra(n, a2, b2) << endl;

    return 0;
}
