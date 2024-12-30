// Link: https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        double low = 0, high = stations[n - 1], ans = 1e9;
        while (high - low > 0.00001)
        {
            double mid = low + (high - low) / 2;
            int count = k;
            for (int i = 1; i < stations.size(); i++)
                count -= max(0, (int)(ceil)(((double)(stations[i] - stations[i - 1]) / mid)) - 1);
            if (count >= 0)
            {
                ans = mid;
                high = mid;
            }
            else
                low = mid;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 9;
    cout << obj.findSmallestMaxDist(stations, k) << endl;

    stations = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
    k = 2;
    cout << obj.findSmallestMaxDist(stations, k) << endl;

    return 0;
}