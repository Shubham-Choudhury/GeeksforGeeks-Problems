// Link: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteMid(Node *head)
    {
        if (head == NULL or head->next == NULL)
            return NULL;
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            n++;
        }
        n /= 2;
        Node *prev = head, *curr = head;
        while (n--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> lst = {1, 2, 3, 4, 5};
    Node *head = new Node(lst[0]);
    Node *temp = head;
    for (int i = 1; i < lst.size(); i++)
    {
        temp->next = new Node(lst[i]);
        temp = temp->next;
    }
    head = obj.deleteMid(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    lst = {2, 4, 6, 7, 5, 1};
    head = new Node(lst[0]);
    temp = head;
    for (int i = 1; i < lst.size(); i++)
    {
        temp->next = new Node(lst[i]);
        temp = temp->next;
    }
    head = obj.deleteMid(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}