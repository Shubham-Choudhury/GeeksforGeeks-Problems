// Link: https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int rotateDelete(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0];
        }
        if (n & 1)
        {
            return arr[floor((n - 3) / 4) + 2];
        }
        else
        {
            return arr[floor((n - 2) / 4) + 1];
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << obj.rotateDelete(arr) << endl;

    arr = {1, 2, 3, 4};
    cout << obj.rotateDelete(arr) << endl;
    return 0;
}