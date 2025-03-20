// Link: https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        int b = 0, c = 0;
        for (int d : arr)
        {
            int e = max(c, b + d);
            b = c;
            c = e;
        }
        return c;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << obj.findMaxSum(arr) << endl;

    arr = {1, 5, 3};
    cout << obj.findMaxSum(arr) << endl;

    arr = {4, 4, 4, 4};
    cout << obj.findMaxSum(arr) << endl;
    return 0;
}