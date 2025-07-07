// Link: https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> findGreater(vector<int> &arr)
    {
        int n = arr.size();
        map<int, int> freq;

        for (auto it : arr)
        {
            freq[it]++;
        }

        vector<int> res(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && freq[arr[i]] > freq[arr[s.top()]])
            {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 1, 1, 3, 2, 1};
    vector<int> result = sol.findGreater(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    arr = {5, 1, 5, 6, 6};
    result = sol.findGreater(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}