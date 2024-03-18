// Link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

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

    if (*headRef == NULL)
    {
        *headRef = new_node;
    }

    else
    {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}

class Solution
{
public:
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        unordered_multiset<int> mSet;
        int cnt = 0;
        while (head1)
        {
            mSet.insert(head1->data);
            head1 = head1->next;
        }
        while (head2)
        {
            if (mSet.count(x - head2->data))
                cnt++;
            head2 = head2->next;
        }
        return cnt;
    }
};