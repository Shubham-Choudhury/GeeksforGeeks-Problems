// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        int n = arr.size(), cnt = 0, XOR = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            XOR ^= arr[i];
            int temp = XOR ^ k;
            cnt += mp[temp];
            mp[XOR]++;
        }
        return cnt;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << object.subarrayXor(arr, k) << endl;

    arr = {5, 6, 7, 8, 9};
    k = 5;
    cout << object.subarrayXor(arr, k) << endl;

    return 0;
}