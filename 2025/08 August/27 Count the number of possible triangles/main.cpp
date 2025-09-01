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
        int res = 0;
        sort(arr.begin(), arr.end());

        for (int i = 2; i < arr.size(); ++i)
        {
            int left = 0, right = i - 1;

            while (left < right)
            {
                if (arr[left] + arr[right] > arr[i])
                {
                    res += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 6, 3, 7};
    int result = sol.countTriangles(arr);
    cout << "Number of possible triangles: " << result << endl;

    arr = {10, 21, 22, 100, 101, 200, 300};
    result = sol.countTriangles(arr);
    cout << "Number of possible triangles: " << result << endl;

    arr = {1, 2, 3};
    result = sol.countTriangles(arr);
    cout << "Number of possible triangles: " << result << endl;

    return 0;
}