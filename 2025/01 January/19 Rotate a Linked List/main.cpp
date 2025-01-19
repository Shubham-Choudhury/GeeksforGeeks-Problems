// Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

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
    Node *temp = new Node(arr[0]);
    Node *head = temp;
    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        Node *lptr, *itr;
        lptr = head;
        int cnt = 0;
        if (lptr->next != NULL)
        {
            cnt++;
            itr = lptr;
            while (itr->next != NULL)
            {
                itr = itr->next;
                cnt++;
            }
            itr->next = lptr;

            k = k % cnt;
            for (int i = 0; i < k; i++)
            {
                itr = itr->next;
            }
            lptr = itr->next;
            itr->next = NULL;
        }
        return lptr;
    }
};

int main()
{
    Solution object;
    int arr1[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *head = createLinkedList(arr1, n);
    int k = 4;
    head = object.rotate(head, k);
    printList(head);

    int arr2[] = {10, 20, 30, 40};
    n = sizeof(arr2) / sizeof(arr2[0]);
    head = createLinkedList(arr2, n);
    k = 6;
    head = object.rotate(head, k);
    printList(head);
    return 0;
}