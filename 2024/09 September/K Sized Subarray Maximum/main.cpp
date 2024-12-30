// Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < arr.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> result = obj.max_of_subarrays(k, arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    k = 4;
    result = obj.max_of_subarrays(k, arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}