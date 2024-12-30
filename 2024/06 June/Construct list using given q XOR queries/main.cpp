// Link: https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        int xr = 0;
        vector<int> ans;
        for (int i = queries.size() - 1; i >= 0; i--)
        {
            if (queries[i][0] == 0)
            {
                ans.push_back(queries[i][1] ^ xr);
            }
            else
            {
                xr ^= queries[i][1];
            }
        }
        ans.push_back(xr);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> queries = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}};
    int q = queries.size();
    vector<int> result = obj.constructList(q, queries);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    queries = {{0, 2}, {1, 3}, {0, 5}};
    q = queries.size();
    result = obj.constructList(q, queries);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
