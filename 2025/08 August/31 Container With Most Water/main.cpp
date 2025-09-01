// Link: https://www.geeksforgeeks.org/problems/container-with-most-water0535/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while (left < right)
        {
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);

            if (arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 5, 4, 3};
    int result = sol.maxWater(arr);
    cout << "Maximum water that can be contained: " << result << endl;

    arr = {3, 1, 2, 4, 5};
    result = sol.maxWater(arr);
    cout << "Maximum water that can be contained: " << result << endl;

    arr = {2, 1, 8, 6, 4, 6, 5, 5};
    result = sol.maxWater(arr);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}