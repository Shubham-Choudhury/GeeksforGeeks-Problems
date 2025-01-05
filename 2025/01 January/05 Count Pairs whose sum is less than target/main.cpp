// Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0, j = n - 1, count = 0;
        while (i < j)
        {
            int sum = arr[i] + arr[j];

            if (sum >= target)
                j--;
            else
            {
                count = count + (j - i);
                i++;
            }
        }
        return count;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {7, 2, 5, 3};
    int target = 8;
    cout << object.countPairs(arr, target) << endl;

    arr = {5, 2, 3, 2, 4, 1};
    target = 5;
    cout << object.countPairs(arr, target) << endl;

    arr = {2, 1, 8, 3, 4, 7, 6, 5};
    target = 7;
    cout << object.countPairs(arr, target) << endl;
    return 0;
}