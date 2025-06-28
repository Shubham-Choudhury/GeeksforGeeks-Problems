// Link: https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countLessEq(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        vector<int> res(n);

        int maxi = *max_element(b.begin(), b.end());

        vector<int> cnt(maxi + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cnt[b[i]]++;
        }

        for (int i = 1; i < maxi + 1; i++)
        {
            cnt[i] += cnt[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            res[i] = cnt[min(a[i], maxi)];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {4, 8, 7, 5, 1};
    vector<int> b = {4, 48, 3, 0, 1, 1, 5};
    vector<int> result = sol.countLessEq(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    a = {10, 20};
    b = {30, 40, 50};
    result = sol.countLessEq(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}