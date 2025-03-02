// Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        map<int, int> hash;
        vector<int> ans;
        int n = arr.size();
        k--;
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
            if (i >= k)
            {
                ans.push_back(hash.rbegin()->first);
                if (--hash[arr[i - k]] == 0)
                    hash.erase(arr[i - k]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> ans = object.maxOfSubarrays(arr, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    k = 4;
    ans = object.maxOfSubarrays(arr, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    arr = {5, 1, 3, 4, 2, 6};
    k = 1;
    ans = object.maxOfSubarrays(arr, k);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}