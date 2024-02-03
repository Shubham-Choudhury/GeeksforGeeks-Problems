// Link: https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1

#include <iostream>
using namespace std;

struct Node
{
    bool data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    long long unsigned int decimalValue(Node *head)
    {
        long long unsigned int ans = 0;
        int mod = 1e9 + 7;
        while (head)
        {
            ans = ans << 1;
            if (head->data)
                ans++;
            head = head->next;
            ans %= mod;
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(1);
    cout << obj.decimalValue(head) << endl;

    head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    cout << obj.decimalValue(head) << endl;
    return 0;
}