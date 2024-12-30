// Link: https://www.geeksforgeeks.org/problems/top-k-numbers3425/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kTop(vector<int> &arr, int N, int K)
    {
        vector<vector<int>> ans;
        vector<int> top(K + 1);

        unordered_map<int, int> freq;

        for (int m = 0; m < N; m++)
        {
            freq[arr[m]]++;

            top[K] = arr[m];

            auto it = find(top.begin(), top.end() - 1, arr[m]);

            for (int i = distance(top.begin(), it) - 1; i >= 0; --i)
            {

                if (freq[top[i]] < freq[top[i + 1]])
                    swap(top[i], top[i + 1]);

                else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1]))
                    swap(top[i], top[i + 1]);
                else
                    break;
            }

            vector<int> temp;
            for (int i = 0; i < K && top[i] != 0; ++i)
                temp.push_back(top[i]);
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    int N = 5;
    int K = 4;
    vector<int> arr = {5, 2, 1, 3, 2};
    vector<vector<int>> ans = obj.kTop(arr, N, K);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    N = 6;
    K = 3;
    vector<int> arr1 = {2, 1, 2, 1, 2, 1};
    vector<vector<int>> ans1 = obj.kTop(arr1, N, K);
    for (int i = 0; i < ans1.size(); ++i)
    {
        for (int j = 0; j < ans1[i].size(); ++j)
            cout << ans1[i][j] << " ";
        cout << endl;
    }
    return 0;
}