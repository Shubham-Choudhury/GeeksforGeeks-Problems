// Link: https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        int suma = accumulate(a, a + n, 0);
        int sumb = accumulate(b, b + m, 0);

        if ((suma - sumb) % 2 != 0)
        {
            return -1;
        }

        int diff = (suma - sumb) / 2;
        unordered_set<int> setA(a, a + n);

        for (int i = 0; i < m; i++)
        {
            int bx = b[i];
            int ax = bx + diff;
            if (setA.find(ax) != setA.end())
            {
                return 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;
    int a1[] = {4, 1, 2, 1, 1, 2};
    int b1[] = {3, 6, 3, 3};
    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(b1) / sizeof(int);
    cout << obj.findSwapValues(a1, n, b1, m) << endl;

    int a2[] = {5, 7, 4, 6};
    int b2[] = {1, 2, 3, 8};
    n = sizeof(a2) / sizeof(int);
    m = sizeof(b2) / sizeof(int);
    cout << obj.findSwapValues(a2, n, b2, m) << endl;

    return 0;
}
