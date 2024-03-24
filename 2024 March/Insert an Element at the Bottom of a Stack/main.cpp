// Link: https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> st, int x)
    {

        vector<int> a;
        while (!st.empty())
        {
            a.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for (int i = a.size() - 1; i >= 0; i--)
        {
            st.push(a[i]);
        }
        return st;
    }
};

int main()
{
    Solution obj;
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);
    stack<int> res = obj.insertAtBottom(st, 5);
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}