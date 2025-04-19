// Link: https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        long long actual_sum = accumulate(arr.begin(), arr.end(), 0ll);
        long long expected_sum = (1LL * (n - 1) * n) / 2;
        return actual_sum - expected_sum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 3, 2, 3, 4};
    cout << "The duplicate element is: " << obj.findDuplicate(arr) << endl;

    arr = {1, 5, 1, 2, 3, 4};
    cout << "The duplicate element is: " << obj.findDuplicate(arr) << endl;

    arr = {1, 1};
    cout << "The duplicate element is: " << obj.findDuplicate(arr) << endl;
    return 0;
}