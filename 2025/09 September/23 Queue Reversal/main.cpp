// Link: https://www.geeksforgeeks.org/problems/queue-reversal/1

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    void reverseQueue(queue<int> &q)
    {
        stack<int> st;

        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }
};

int main()
{
    Solution sol;
    queue<int> q;
    vector<int> elements = {5, 10, 15, 20, 25};
    for (int elem : elements)
    {
        q.push(elem);
    }
    sol.reverseQueue(q);
    cout << "Reversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    elements = {1, 2, 3, 4, 5};
    for (int elem : elements)
    {
        q.push(elem);
    }
    sol.reverseQueue(q);
    cout << "Reversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}