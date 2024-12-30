// Link: https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findTriplets(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]] = i;
        }
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                int third = -(arr[i] + arr[j]);
                if (mpp.find(third) != mpp.end() && mpp[third] != i && mpp[third] != j)
                {
                    vector<int> temp = {i, j, mpp[third]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mpp[arr[j]] = j;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> result = object.findTriplets(arr);
    for (auto triplet : result)
    {
        for (auto element : triplet)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;

    arr = {1, -2, 1, 0, 5};
    result = object.findTriplets(arr);
    for (auto triplet : result)
    {
        for (auto element : triplet)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;

    arr = {2, 3, 1, 0, 5};
    result = object.findTriplets(arr);
    for (auto triplet : result)
    {
        for (auto element : triplet)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}