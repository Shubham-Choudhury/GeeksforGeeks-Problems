// Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            double t1 = (double)arr[i].value / arr[i].weight;
            v[i] = make_pair(t1, i);
        }
        sort(v.rbegin(), v.rend());
        double ans = 0;
        for (auto x : v)
        {
            if (arr[x.second].weight <= W)
            {
                ans += arr[x.second].value;
                W -= arr[x.second].weight;
            }
            else
            {
                ans += x.first * W;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 3, W = 50;
    Item arr[N];
    arr[0].value = 60;
    arr[0].weight = 10;
    arr[1].value = 100;
    arr[1].weight = 20;
    arr[2].value = 120;
    arr[2].weight = 30;
    cout << obj.fractionalKnapsack(W, arr, N) << endl;

    N = 2, W = 50;
    Item arr1[N];
    arr1[0].value = 60;
    arr1[0].weight = 10;
    arr1[1].value = 100;
    arr1[1].weight = 20;
    cout << obj.fractionalKnapsack(W, arr1, N) << endl;
    return 0;
}