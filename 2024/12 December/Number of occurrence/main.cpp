// Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        int n = arr.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == target)
                c++;
        }
        return c;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3};
    int target = 2;
    cout << object.countFreq(arr, target) << endl;

    arr = {1, 1, 2, 2, 2, 2, 3};
    target = 4;
    cout << object.countFreq(arr, target) << endl;

    arr = {8, 9, 10, 12, 12, 12};
    target = 12;
    cout << object.countFreq(arr, target) << endl;
    return 0;
}