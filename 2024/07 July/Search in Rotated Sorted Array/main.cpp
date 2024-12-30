// Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        int l = 0;
        int h = arr.size() - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] == key)
                return mid;

            else if (arr[l] <= arr[mid])
            {
                if (arr[l] <= key && arr[mid] >= key)
                    h = mid - 1;
                else
                    l = mid + 1;
            }

            else
            {
                if (arr[h] >= key && arr[mid] <= key)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> A = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 10;
    cout << obj.search(A, key) << endl;

    A = {3, 5, 1, 2};
    key = 6;
    cout << obj.search(A, key) << endl;
    return 0;
}