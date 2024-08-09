// Link: https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int Maximize(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int val = 1000000007;
        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            result = (result + (long long)arr[i] * i) % val;
        }

        return (int)result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << obj.Maximize(arr) << endl;

    arr = {1, 2, 3};
    cout << obj.Maximize(arr) << endl;

    return 0;
}