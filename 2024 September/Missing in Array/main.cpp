// Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += arr[i];
        }
        return n * (n + 1) / 2 - sum;
    }
};

int main()
{
    Solution obj;
    int n = 5;
    vector<int> arr = {1, 2, 3, 5};
    cout << obj.missingNumber(n, arr) << endl;
    n = 2;
    arr = {1};
    cout << obj.missingNumber(n, arr) << endl;
    return 0;
}