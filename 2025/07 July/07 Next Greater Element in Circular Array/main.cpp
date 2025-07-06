// Link: https://www.geeksforgeeks.org/problems/next-greater-element/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() <= arr[i % n])
            {
                stk.pop();
            }

            if (i < n && !stk.empty())
            {
                res[i] = stk.top();
            }

            stk.push(arr[i % n]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 2, 4};
    vector<int> result = sol.nextLargerElement(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    arr = {0, 2, 3, 1, 1};
    result = sol.nextLargerElement(arr);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}