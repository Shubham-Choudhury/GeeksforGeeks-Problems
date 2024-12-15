// Link: https://www.geeksforgeeks.org/problems/peak-element/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peakElement(vector<int> &arr)
    {
        int L = 0;
        int R = arr.size() - 1;
        if (L == R)
            return 0;
        while (L <= R)
        {
            int M = (L + R) / 2;
            if (M == 0 && arr[M] > arr[M + 1])
                return M;
            else if (M == arr.size() - 1 && arr[M] > arr[M - 1])
                return M;
            else if (arr[M] > arr[M + 1] && arr[M] > arr[M - 1])
                return M;
            else if (arr[M] > arr[M + 1])
            {
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << object.peakElement(arr) << endl;

    arr = {10, 20, 15, 2, 23, 90, 80};
    cout << object.peakElement(arr) << endl;

    arr = {1, 2, 3};
    cout << object.peakElement(arr) << endl;
    return 0;
}