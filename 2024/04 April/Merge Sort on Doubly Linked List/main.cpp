// Link: https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insert(struct Node **head, int data)
{
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (head)
    {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

class Solution
{
private:
    Node *split(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node *temp = slow->next;
        slow->next = NULL;
        return temp;
    }

    Node *mergeSort(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *second = split(head);

        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head, second);
    }

    Node *merge(Node *first, Node *second)
    {
        if (!first)
            return second;

        if (!second)
            return first;

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }

public:
    struct Node *sortDoubly(struct Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *second = split(head);

        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head, second);
    }
};

int main()
{
    Solution obj;
    vector<int> values = {7, 3, 5, 2, 6, 4, 1, 8};
    Node *head1 = nullptr;
    for (int i : values)
    {
        insert(&head1, i);
    }
    head1 = obj.sortDoubly(head1);
    print(head1);

    values = {9, 15, 0, -1, 0};
    Node *head2 = nullptr;
    for (int i : values)
    {
        insert(&head2, i);
    }
    head2 = obj.sortDoubly(head2);
    print(head2);

    return 0;
}