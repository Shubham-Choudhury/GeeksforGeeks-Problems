// Link: https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        int res[m + 1] = {};
        for (int i = 0; i < n; i++)
        {
            for (int j = min(m, i + 1); j > 0; j--)
                res[j] = max(res[j], a[i] * b[j - 1] + res[j - 1]);
        }
        return res[m];
    }
};

int main()
{
    Solution obj;
    int a1[] = {2, 3, 1, 7, 8};
    int b1[] = {3, 6, 7};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int m1 = sizeof(b1) / sizeof(b1[0]);
    cout << obj.maxDotProduct(n1, m1, a1, b1) << endl;

    int a2[] = {9, 3, 9, 2, 3, 5, 4, 1, 8, 8};
    int b2[] = {10, 4, 3, 8};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int m2 = sizeof(b2) / sizeof(b2[0]);
    cout << obj.maxDotProduct(n2, m2, a2, b2) << endl;

    return 0;
}