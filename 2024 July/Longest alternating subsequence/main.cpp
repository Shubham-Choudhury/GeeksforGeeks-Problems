// Link: https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int alternatingMaxLength(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return n;

        int up = 1, down = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                up = down + 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 5, 4};
    cout << obj.alternatingMaxLength(arr) << endl;

    arr = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << obj.alternatingMaxLength(arr) << endl;

    return 0;
}