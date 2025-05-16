// Link: https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int val, row, col;
        bool operator>(const Node &other) const
        {
            return val > other.val;
        }
    };

    vector<int> findSmallestRange(vector<vector<int>> &arr)
    {
        int N = arr.size();
        int K = arr[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int maxVal = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            pq.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }

        int minRange = INT_MAX, minEl, maxEl;

        while (true)
        {
            Node curr = pq.top();
            pq.pop();
            int minVal = curr.val;

            if (maxVal - minVal < minRange)
            {
                minRange = maxVal - minVal;
                minEl = minVal;
                maxEl = maxVal;
            }

            if (curr.col + 1 == K)
                break;

            int nextVal = arr[curr.row][curr.col + 1];
            pq.push({nextVal, curr.row, curr.col + 1});
            maxVal = max(maxVal, nextVal);
        }

        return {minEl, maxEl};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};
    vector<int> result = sol.findSmallestRange(arr);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;

    arr = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}};
    result = sol.findSmallestRange(arr);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;

    arr = {
        {2, 4},
        {1, 7},
        {20, 40}};
    result = sol.findSmallestRange(arr);
    cout << "Smallest range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}