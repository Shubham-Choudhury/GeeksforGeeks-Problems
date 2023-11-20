// Link: https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *temp = new Node(-1);
        Node *sum = temp;
        while (head1 && head2)
        {
            if (head1->data == head2->data)
            {
                sum->next = new Node(head2->data);
                sum = sum->next;
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->data > head2->data)
            {
                head2 = head2->next;
            }
            else
            {
                head1 = head1->next;
            }
        }
        return temp->next;
    }
};

int main()
{
    Solution obj;
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);
    head1->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next = new Node(8);
    head1->next->next->next->next->next->next->next = new Node(9);
    head1->next->next->next->next->next->next->next->next = new Node(10);
    head1->next->next->next->next->next->next->next->next->next = new Node(11);
    head1->next->next->next->next->next->next->next->next->next->next = new Node(12);
    head1->next->next->next->next->next->next->next->next->next->next->next = new Node(13);
    head1->next->next->next->next->next->next->next->next->next->next->next->next = new Node(14);

    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    head2->next->next->next->next->next = new Node(12);
    head2->next->next->next->next->next->next = new Node(14);
    head2->next->next->next->next->next->next->next = new Node(15);
    head2->next->next->next->next->next->next->next->next = new Node(16);
    head2->next->next->next->next->next->next->next->next->next = new Node(17);
    head2->next->next->next->next->next->next->next->next->next->next = new Node(18);

    Node *ans = obj.findIntersection(head1, head2);
    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}