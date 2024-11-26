// Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
            st.insert(arr[i]);

        for (int i = 1; i <= INT_MAX; i++)
        {
            if (st.find(i) == st.end())
                return i;
        }

        return 1;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << object.missingNumber(arr) << endl;
    arr = {5, 3, 2, 5, 1};
    cout << object.missingNumber(arr) << endl;
    arr = {-8, 0, -1, -4, -3};
    cout << object.missingNumber(arr) << endl;
    return 0;
}