// Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

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

Node *createLinkedList(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);

        temp = temp->next;
    }
}

class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        Node *temp = head;
        Node *prev = NULL;
        Node *forward = NULL;
        while (temp)
        {
            forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }
};

int main()
{
    Solution object;
    int arr1[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *head = createLinkedList(arr1, n);
    head = object.reverseList(head);
    printList(head);
    cout << endl;

    int arr2[] = {2, 7, 8, 9, 10};
    n = sizeof(arr2) / sizeof(arr2[0]);
    head = createLinkedList(arr2, n);
    head = object.reverseList(head);
    printList(head);
    return 0;
}