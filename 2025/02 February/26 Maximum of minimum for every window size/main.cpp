// Link: https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> maxOfMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n, 0);
        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> s;

        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                left[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                right[i] = s.top();
            }
            s.push(i);
        }

        for (int i = 0; i < n; ++i)
        {
            int window_size = right[i] - left[i] - 1;
            result[window_size - 1] = max(result[window_size - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; --i)
        {
            result[i] = max(result[i], result[i + 1]);
        }

        return result;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = object.maxOfMins(arr);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {10, 20, 30};
    result = object.maxOfMins(arr);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}