// Link: https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long findSmallest(vector<int> &arr)
    {
        long long t = 1;
        for (int &i : arr)
        {
            if (t < i)
                return t;
            t = t + i;
        }
        return t;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3};
    cout << obj.findSmallest(arr) << endl;

    arr = {3, 6, 9, 10, 20, 28};
    cout << obj.findSmallest(arr) << endl;
    return 0;
}