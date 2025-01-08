// Link: https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countTriangles(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;
        ;
        sort(arr.begin(), arr.end());
        int triangleCount = 0;
        for (int k = n - 1; k >= 2; k--)
        {
            int i = 0, j = k - 1;
            while (i < j)
            {
                if (arr[i] + arr[j] > arr[k])
                {
                    triangleCount += (j - i);
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return triangleCount;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {4, 6, 3, 7};
    cout << object.countTriangles(arr) << endl;

    arr = {10, 21, 22, 100, 101, 200, 300};
    cout << object.countTriangles(arr) << endl;

    arr = {1, 2, 3};
    cout << object.countTriangles(arr) << endl;
    return 0;
}