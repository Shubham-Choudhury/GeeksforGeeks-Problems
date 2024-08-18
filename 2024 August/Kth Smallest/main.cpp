// Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();

        priority_queue<int> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << obj.kthSmallest(arr, k) << endl;

    arr = {7, 10, 4, 20, 15};
    k = 4;
    cout << obj.kthSmallest(arr, k) << endl;
    return 0;
}