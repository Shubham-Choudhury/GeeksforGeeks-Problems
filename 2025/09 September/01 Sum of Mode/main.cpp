// Link: https://www.geeksforgeeks.org/problems/sum-of-mode/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    int sumOfModes(vector<int> &arr, int k)
    {
        int n = arr.size();
        int sum = 0;

        unordered_map<int, int> mp;

        set<pair<int, int>> st;

        for (int i = 0; i < k; i++)
        {
            mp[arr[i]]++;
        }

        for (auto x : mp)
        {
            st.insert({x.second, -x.first});
        }

        int mode = -st.rbegin()->second;
        sum += mode;

        for (int i = k; i < n; i++)
        {
            int out = arr[i - k];
            int in = arr[i];

            st.erase({mp[out], -out});

            mp[out]--;

            if (mp[out] > 0)
            {
                st.insert({mp[out], -out});
            }
            else
            {
                mp.erase(out);
            }

            mp[in]++;

            st.insert({mp[in], -in});

            mode = -st.rbegin()->second;
            sum += mode;
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 5, 2, 4, 4};
    int k = 3;
    int result = sol.sumOfModes(arr, k);
    cout << "Sum of modes for window size " << k << ": " << result << endl;

    arr = {1, 2, 1, 3, 5};
    k = 2;
    result = sol.sumOfModes(arr, k);
    cout << "Sum of modes for window size " << k << ": " << result << endl;

    arr = {1, 1, 1, 1};
    k = 2;
    result = sol.sumOfModes(arr, k);
    cout << "Sum of modes for window size " << k << ": " << result << endl;

    return 0;
}