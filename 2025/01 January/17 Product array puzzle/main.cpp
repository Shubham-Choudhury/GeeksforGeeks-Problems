// Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n, 1);
        int left = 1, right = 1;
        for (int i = 1; i < n; i++)
        {
            left *= arr[i - 1];
            result[i] *= left;

            right *= arr[n - i];
            result[n - i - 1] *= right;
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> resule = object.productExceptSelf(arr);
    for (int i = 0; i < resule.size(); i++)
    {
        cout << resule[i] << " ";
    }
    cout << endl;

    arr = {12, 0};
    resule = object.productExceptSelf(arr);
    for (int i = 0; i < resule.size(); i++)
    {
        cout << resule[i] << " ";
    }
    cout << endl;
    return 0;
}