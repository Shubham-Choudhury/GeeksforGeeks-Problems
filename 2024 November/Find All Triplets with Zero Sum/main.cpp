// Link: https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = n - 1; i > 1; i--)
        {
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int j = 1; j < n; j++)
        {
            if (j >= 2)
            {
                mp[arr[j]].pop_back();
                if (!mp[arr[j]].size())
                    mp.erase(arr[j]);
            }
            for (int i = 0; i < j; i++)
            {
                int sum = arr[i] + arr[j];
                if (mp.count(-sum))
                {
                    for (int &k : mp[-sum])
                    {
                        ans.push_back({i, j, k});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> result = object.findTriplets(arr);
    for (auto &triplet : result)
    {
        cout << "[ ";
        for (int &num : triplet)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    arr = {1, -2, 1, 0, 5};
    result = object.findTriplets(arr);
    for (auto &triplet : result)
    {
        cout << "[ ";
        for (int &num : triplet)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;

    arr = {2, 3, 1, 0, 5};
    result = object.findTriplets(arr);
    for (auto &triplet : result)
    {
        cout << "[ ";
        for (int &num : triplet)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}