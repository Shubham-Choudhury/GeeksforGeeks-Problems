// Link: https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<pair<int, int>> v;
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            v.push_back({price[i], i + 1});
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i)
        {
            int stocks = k / v[i].first;
            int temp = min(stocks, v[i].second);
            k = k - temp * v[i].first;
            ans += temp;
        }
        return ans;
    }
};

int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;
    Solution obj;
    cout << obj.buyMaximumProducts(n, k, price) << endl;
    return 0;
}