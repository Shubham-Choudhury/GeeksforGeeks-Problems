// Link: https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto &p : points)
        {
            int dist = p[0] * p[0] + p[1] * p[1];
            maxHeap.push({dist, p});
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty())
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    vector<vector<int>> result = object.kClosest(points, k);
    for (auto &p : result)
    {
        cout << p[0] << " " << p[1] << endl;
    }
    cout << endl;

    points = {{2, 4}, {-1, -1}, {0, 0}};
    k = 1;
    result = object.kClosest(points, k);
    for (auto &p : result)
    {
        cout << p[0] << " " << p[1] << endl;
    }
    cout << endl;
    return 0;
}