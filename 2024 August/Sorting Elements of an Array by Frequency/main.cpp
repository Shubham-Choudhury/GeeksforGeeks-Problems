// Link: https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
            return true;
        else if (a.first == b.first)
            return (a.second < b.second);
        else
            return false;
    }

public:
    vector<int> sortByFreq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
        vector<pair<int, int>> temp;
        for (auto x : m)
            temp.push_back(make_pair(x.second, x.first));
        temp.shrink_to_fit();
        sort(temp.begin(), temp.end(), cmp);
        vector<int> res;
        for (int i = 0; i < temp.size(); i++)
        {
            int t = temp[i].first;
            while (t--)
            {
                res.push_back(temp[i].second);
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 5, 4, 6, 4};
    vector<int> res = obj.sortByFreq(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    arr = {9, 9, 9, 2, 5};
    res = obj.sortByFreq(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}