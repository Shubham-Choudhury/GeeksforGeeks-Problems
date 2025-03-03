// Link: https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        multiset<int> st;
        int strt = 0, l = 0, r = 0, n = arr.size(), sz = 0;
        while (r < n)
        {
            st.insert(arr[r++]);
            while ((*(--st.end())) - *st.begin() > x)
            {
                st.erase(st.find(arr[l++]));
            }
            if (sz < st.size())
            {
                sz = st.size();
                strt = l;
            }
        }
        vector<int> ans;
        while (sz--)
        {
            ans.push_back(arr[strt++]);
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {8, 4, 2, 6, 7};
    int x = 4;
    vector<int> result = object.longestSubarray(arr, x);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    arr = {15, 10, 1, 2, 4, 7, 2};
    x = 5;
    result = object.longestSubarray(arr, x);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}