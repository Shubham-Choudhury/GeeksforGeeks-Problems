// Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits\stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *Reverse(Node *node)
    {
        if (node == NULL || node->next == NULL)
            return node;
        Node *temp = NULL;
        Node *curr = node;
        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        return temp->prev;
    }

    Node *reverseDLL(Node *head)
    {
        // Your code here
        return Reverse(head);
    }
};

int main()
{
    Solution obj;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->prev = head->next->next->next;
    head = obj.reverseDLL(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}