// Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    long long minCost(vector<long long> &arr)
    {

        long long n = arr.size();

        if (n == 1)
            return 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long sum = 0;

        while (!pq.empty())
        {

            if (pq.size() == 1)
            {
                break;
            }

            long long a1 = pq.top();
            pq.pop();
            long long a2 = pq.top();
            pq.pop();
            long long a3 = a1 + a2;
            sum += a3;
            pq.push(a3);
        }

        return sum;
    }
};

int main()
{
    Solution obj;
    vector<long long> arr = {4, 3, 2, 6};
    cout << obj.minCost(arr) << endl;

    arr = {4, 2, 7, 6, 9};
    cout << obj.minCost(arr) << endl;
    return 0;
}