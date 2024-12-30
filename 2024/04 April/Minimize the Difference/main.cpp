// Link: https://www.geeksforgeeks.org/problems/minimize-the-difference/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        deque<int> dqMax;
        deque<int> dqMin;

        int remK = n - k;
        int mindif = INT_MAX;

        for (int i = 0; i < remK - 1; i++)
        {

            while (!dqMax.empty() && dqMax.back() < arr[i + k])
            {
                dqMax.pop_back();
            }
            dqMax.push_back(arr[i + k]);

            while (!dqMin.empty() && dqMin.back() > arr[i + k])
            {
                dqMin.pop_back();
            }
            dqMin.push_back(arr[i + k]);
        }

        int indexS = n - 1;
        int indexL = k;
        for (int i = k - 1; i < n; i++, indexS++, indexL++)
        {

            while (!dqMax.empty() && dqMax.back() < arr[indexS % n])
            {
                dqMax.pop_back();
            }
            dqMax.push_back(arr[indexS % n]);

            while (!dqMin.empty() && dqMin.back() > arr[indexS % n])
            {
                dqMin.pop_back();
            }
            dqMin.push_back(arr[indexS % n]);

            mindif = min(mindif, abs(dqMax.front() - dqMin.front()));

            if (arr[indexL % n] == dqMax.front())
            {
                dqMax.pop_front();
            }

            if (arr[indexL % n] == dqMin.front())
            {
                dqMin.pop_front();
            }
        }

        return mindif;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 3;
    cout << obj.minimizeDifference(n, k, arr) << endl;
    arr = {2, 3, 1, 4, 6, 7};
    n = arr.size();
    k = 3;
    cout << obj.minimizeDifference(n, k, arr) << endl;
    return 0;
}