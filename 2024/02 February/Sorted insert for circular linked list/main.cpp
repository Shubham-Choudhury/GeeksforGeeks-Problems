// Link: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

#include <iostream>
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
    Node *sortedInsert(Node *head, int data)
    {
        Node *new_node = new Node(data);
        Node *t = new_node;

        if (head == nullptr)
        {
            new_node->next = new_node;
            head = new_node;
            return head;
        }

        if (data < head->data)
        {
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            new_node->next = head;
            last->next = new_node;
            head = new_node;
            return head;
        }

        Node *temp = head;
        while (temp->next != head && t->data > temp->next->data)
        {
            temp = temp->next;
        }

        t->next = temp->next;
        temp->next = t;

        return head;
    }
};

int main()
{
    Solution obj;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = head;
    int data = 3;
    head = obj.sortedInsert(head, data);
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
    return 0;
}