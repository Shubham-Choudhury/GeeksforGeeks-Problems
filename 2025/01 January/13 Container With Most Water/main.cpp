// Link: https://www.geeksforgeeks.org/problems/container-with-most-water0535/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = n - 1;
        int maxi = 0;
        while (i < j)
        {
            maxi = max(maxi, min(arr[i], arr[j]) * (j - i));

            if (arr[i] <= arr[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 5, 4, 3};
    cout << object.maxWater(arr) << endl;

    arr = {3, 1, 2, 4, 5};
    cout << object.maxWater(arr) << endl;

    arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << object.maxWater(arr) << endl;
    return 0;
}