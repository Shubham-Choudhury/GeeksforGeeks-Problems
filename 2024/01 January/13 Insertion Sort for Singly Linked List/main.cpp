// Link: https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1

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
    Node *insertionSort(struct Node *head_ref)
    {
        if (head_ref == NULL)
        {
            return head_ref;
        }

        Node *dummy = new Node(0);
        Node *curr = head_ref;
        Node *pre = dummy;
        Node *nex = NULL;

        while (curr != NULL)
        {
            nex = curr->next;
            while (pre->next != NULL && pre->next->data < curr->data)
            {
                pre = pre->next;
            }

            curr->next = pre->next;
            pre->next = curr;
            pre = dummy;
            curr = nex;
        }

        return dummy->next;
    }
};

int main()
{
    Solution obj;
    int N = 10;
    int arr[] = {30, 23, 28, 30, 11, 14, 19, 16, 21, 25};
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < N; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    head = obj.insertionSort(head);
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << endl;

    int N2 = 7;
    int arr2[] = {19, 20, 16, 24, 12, 29, 30};
    Node *head2 = new Node(arr2[0]);
    Node *tail2 = head2;
    for (int i = 1; i < N2; i++)
    {
        tail2->next = new Node(arr2[i]);
        tail2 = tail2->next;
    }
    head2 = obj.insertionSort(head2);
    for (Node *curr = head2; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << endl;
    return 0;
}