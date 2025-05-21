// Link: https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int count(int val, int m, int n)
    {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
        {
            cnt += min(val / i, n);
        }
        return cnt;
    };

    int kthSmallest(int m, int n, int k)
    {
        int l = 1, h = m * n;
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (count(mid, m, n) < k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return l;
    }
};

int main()
{
    Solution obj;
    int m = 3, n = 3, k = 5;
    cout << obj.kthSmallest(m, n, k) << endl;
    m = 2, n = 3, k = 6;
    cout << obj.kthSmallest(m, n, k) << endl;
    return 0;
}