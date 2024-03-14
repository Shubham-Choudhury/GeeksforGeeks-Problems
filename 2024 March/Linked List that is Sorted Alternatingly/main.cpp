// Link: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

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

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    void reverselist(Node *&head)
    {
        Node *prev = NULL, *curr = head, *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    Node *mergelist(Node *head1, Node *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        Node *temp = NULL;

        if (head1->data < head2->data)
        {
            temp = head1;
            head1->next = mergelist(head1->next, head2);
        }
        else
        {
            temp = head2;
            head2->next = mergelist(head1, head2->next);
        }
        return temp;
    }

    void splitList(Node *head, Node **Ahead, Node **Dhead)
    {
        *Ahead = new Node(0);
        *Dhead = new Node(0);

        Node *ascn = *Ahead;
        Node *dscn = *Dhead;
        Node *curr = head;

        while (curr)
        {
            ascn->next = curr;
            ascn = ascn->next;
            curr = curr->next;

            if (curr)
            {
                dscn->next = curr;
                dscn = dscn->next;
                curr = curr->next;
            }
        }
        ascn->next = NULL;
        dscn->next = NULL;
        *Ahead = (*Ahead)->next;
        *Dhead = (*Dhead)->next;
    }

    void sort(Node **head)
    {
        Node *Ahead, *Dhead;
        splitList(*head, &Ahead, &Dhead);
        reverselist(Dhead);
        *head = mergelist(Ahead, Dhead);
    }
};

int main()
{
    Solution obj;
    vector<int> list = {1, 9, 2, 8, 3, 7};
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < list.size(); i++)
    {
        append(&head, &tail, list[i]);
    }
    obj.sort(&head);
    printList(head);

    list = {13, 99, 21, 80, 50};
    head = NULL, tail = NULL;
    for (int i = 0; i < list.size(); i++)
    {
        append(&head, &tail, list[i]);
    }
    obj.sort(&head);
    printList(head);

    return 0;
}