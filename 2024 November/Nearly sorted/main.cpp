// Link: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k + 1; i++)
        {
            pq.push(arr[i]);
        }

        int temp = k + 1;

        for (int i = 0; i < n; i++)
        {
            arr[i] = pq.top();
            pq.pop();
            if (temp < n)
                pq.push(arr[temp]);
            temp++;
        }
    }
};

int main()
{
    Solution object;
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    object.nearlySorted(arr, k);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
    k = 2;
    object.nearlySorted(arr, k);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}