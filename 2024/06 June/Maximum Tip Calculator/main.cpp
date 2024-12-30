// Link: https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<vector<int>> temp(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            temp[i][0] = arr[i] - brr[i];
            temp[i][1] = arr[i];
            temp[i][2] = brr[i];
        }

        sort(temp.begin(), temp.end(), [](const vector<int> &a, const vector<int> &b)
             { return abs(a[0]) > abs(b[0]); });

        long long res = 0, a = 0, b = 0;

        for (const auto &t : temp)
        {
            int d = t[0], i = t[1], j = t[2];
            if ((d >= 0 && a < x) || b == y)
            {
                res += i;
                a++;
            }
            else
            {
                res += j;
                b++;
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    int n = 5;
    int x = 3;
    int y = 3;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> brr = {5, 4, 3, 2, 1};
    cout << obj.maxTip(n, x, y, arr, brr) << endl;

    n = 8;
    x = 4;
    y = 4;
    arr = {1, 4, 3, 2, 7, 5, 9, 6};
    brr = {1, 2, 3, 6, 5, 4, 9, 8};
    cout << obj.maxTip(n, x, y, arr, brr) << endl;
}