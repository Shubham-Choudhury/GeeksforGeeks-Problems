// Link: https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int res = 0;
        int start = 0, end = 0;
        int cnt = 0;

        while (end < arr.size())
        {
            if (arr[end] == 0)
                cnt++;

            while (cnt > k)
            {
                if (arr[start] == 0)
                    cnt--;

                start++;
            }

            res = max(res, (end - start + 1));
            end++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 0, 1};
    int k = 1;
    int result = sol.maxOnes(arr, k);
    cout << "Maximum number of 1's after flipping " << k << " zeroes: " << result << endl;

    arr = {1, 0, 0, 1, 0, 1, 0, 1};
    k = 2;
    result = sol.maxOnes(arr, k);
    cout << "Maximum number of 1's after flipping " << k << " zeroes: " << result << endl;

    arr = {1, 1};
    k = 2;
    result = sol.maxOnes(arr, k);
    cout << "Maximum number of 1's after flipping " << k << " zeroes: " << result << endl;

    return 0;
}