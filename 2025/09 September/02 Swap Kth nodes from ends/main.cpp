// Link: https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *createLinkedList(vector<int> arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

class Solution
{
public:
    Node *swapKth(Node *head, int k)
    {
        if (!head)
            return head;

        int n = 0;
        Node *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

        if (k > n)
            return head;

        if (2 * k - 1 == n)
            return head;

        Node *prevX = nullptr;
        Node *x = head;
        for (int i = 1; i < k; i++)
        {
            prevX = x;
            x = x->next;
        }

        Node *prevY = nullptr;
        Node *y = head;
        for (int i = 1; i < n - k + 1; i++)
        {
            prevY = y;
            y = y->next;
        }

        if (prevX)
            prevX->next = y;
        if (prevY)
            prevY->next = x;

        Node *tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;

        if (k == 1)
            head = y;
        if (k == n)
            head = x;

        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 2, 3, 4, 1};
    int k = 1;
    Node *head = createLinkedList(arr);
    cout << "Original list: ";
    printLinkedList(head);
    head = sol.swapKth(head, k);
    cout << "List after swapping " << k << "th nodes from end and beginning: ";
    printLinkedList(head);

    arr = {5, 9, 8, 5, 10, 3};
    k = 2;
    head = createLinkedList(arr);
    cout << "Original list: ";
    printLinkedList(head);
    head = sol.swapKth(head, k);
    cout << "List after swapping " << k << "th nodes from end and beginning: ";
    printLinkedList(head);

    return 0;
}