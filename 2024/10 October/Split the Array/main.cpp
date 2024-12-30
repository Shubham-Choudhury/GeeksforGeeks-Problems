// Link: https://www.geeksforgeeks.org/problems/split-the-array0238/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countgroup(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
            ans ^= arr[i];
        int val = 1;
        for (int i = 0; i < n - 1; i++)
        {
            val *= 2;
            val %= mod;
        }
        return ans == 0 ? val - 1 : 0;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3};
    cout << obj.countgroup(arr) << endl;

    arr = {5, 2, 3, 2};
    cout << obj.countgroup(arr) << endl;
    return 0;
}