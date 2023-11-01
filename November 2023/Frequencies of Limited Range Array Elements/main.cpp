// Link: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < N; i++)
        {
            arr[i] = mp[i + 1];
        }
    }
};

int main()
{
    Solution obj;
    int arr[] = {
        2, 3, 2, 3, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int P = 5;
    vector<int> v(arr, arr + N);
    obj.frequencyCount(v, N, P);
    for (int i = 0; i < N; i++)
        cout << v[i] << " ";
}