// Link: https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMissing(vector<int> &arr)
    {
        int n = arr.size();

        int diff = (arr[1] - arr[0] == arr[n - 1] - arr[n - 2]) ? arr[1] - arr[0] : ((arr[1] - arr[0] == (arr[n - 1] - arr[0]) / n) ? arr[1] - arr[0] : arr[n - 1] - arr[n - 2]);

        if (diff == 0)
            return arr[0];

        long long s = (2LL * arr[0] + n * diff) * (n + 1) / 2;

        int sum = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            sum = sum + arr[i];
        }
        return s - sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 4, 8, 10, 12, 14};
    cout << "The missing element is: " << sol.findMissing(arr) << endl;

    arr = {1, 6, 11, 16, 21, 31};
    cout << "The missing element is: " << sol.findMissing(arr) << endl;

    arr = {4, 7, 10, 13, 16};
    cout << "The missing element is: " << sol.findMissing(arr) << endl;

    return 0;
}