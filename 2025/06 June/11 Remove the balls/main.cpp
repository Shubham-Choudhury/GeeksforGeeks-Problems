// Link: https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> color, vector<int> radius)
    {
        int n = color.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && color[i] == color[st.top()] &&
                radius[i] == radius[st.top()])
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }

        return st.size();
    }
};

int main()
{
    Solution sol;
    vector<int> color = {2, 3, 5};
    vector<int> radius = {3, 3, 5};
    int result = sol.findLength(color, radius);
    cout << result << endl;

    color = {2, 2, 5};
    radius = {3, 3, 5};
    result = sol.findLength(color, radius);
    cout << result << endl;

    return 0;
}