// Link: https://www.geeksforgeeks.org/problems/total-count2415/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalCount(int k, vector<int> &arr)
    {
        int sum = 0;
        for (int i : arr)
        {
            int div = i / k;
            sum = sum + div;
            int rem = i % k;
            if (rem != 0)
            {
                sum = sum + 1;
            }
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    int k = 3;
    vector<int> arr = {5, 8, 10, 13};
    cout << obj.totalCount(k, arr) << endl;

    k = 4;
    arr = {10, 2, 3, 4, 7};
    cout << obj.totalCount(k, arr) << endl;
    return 0;
}