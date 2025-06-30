// Link: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    queue<int> modifyQueue(queue<int> q, int k)
    {
        stack<int> s;
        vector<int> v;
        while (k > 0)
        {
            int a = q.front();
            q.pop();
            s.push(a);
            k--;
        }
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            v.push_back(a);
        }
        while (!s.empty())
        {
            int a = s.top();
            s.pop();
            q.push(a);
        }
        for (int i = 0; i < v.size(); i++)
        {
            int a = v[i];
            q.push(a);
        }
        return q;
    }
};

int main()
{
    Solution obj;
    int n = 5;
    int k = 3;
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    queue<int> ans = obj.modifyQueue(Queue, k);
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    n = 4;
    k = 4;
    queue<int> Queue2;
    Queue2.push(4);
    Queue2.push(3);
    Queue2.push(2);
    Queue2.push(1);
    queue<int> ans2 = obj.modifyQueue(Queue2, k);
    while (!ans2.empty())
    {
        cout << ans2.front() << " ";
        ans2.pop();
    }
    cout << endl;
    return 0;
}