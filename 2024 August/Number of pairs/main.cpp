// Link: https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<int> &arr, vector<int> &brr)
    {
        int M = arr.size();
        int N = brr.size();
        sort(brr.begin(), brr.end());

        vector<int> countY(1001, 0);
        for (int i = 0; i < N; i++)
        {
            countY[brr[i]]++;
        }

        auto countGreaterThanY = [&](int y) -> int
        {
            return N - (upper_bound(brr.begin(), brr.end(), y) - brr.begin());
        };

        long long result = 0;

        for (int i = 0; i < M; i++)
        {
            int x = arr[i];
            if (x == 0)
                continue;
            if (x == 1)
            {
                result += countY[0];
                continue;
            }
            result += countGreaterThanY(x);
            result += countY[1];
            if (x == 2)
            {
                result -= countY[3];
                result -= countY[4];
            }
            if (x == 3)
            {
                result += countY[2];
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 1, 6};
    vector<int> brr = {1, 5};
    cout << obj.countPairs(arr, brr) << endl;

    arr = {2, 3, 4, 5};
    brr = {1, 2, 3};
    cout << obj.countPairs(arr, brr) << endl;
    return 0;
}