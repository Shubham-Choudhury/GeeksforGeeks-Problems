// Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

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

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        Node *temp = head;
        Node *dum = head;
        int c = 0;
        stack<int> st;

        while (temp != NULL)
        {
            while (c < k && temp != NULL)
            {
                st.push(temp->data);
                temp = temp->next;
                c++;
            }
            while (!st.empty())
            {
                dum->data = st.top();
                dum = dum->next;
                st.pop();
            }
            c = 0;
        }
        return head;
    }
};

int main()
{
    Solution object;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 4;
    Node *head = createLinkedList(arr1, n);
    head = object.reverseKGroup(head, k);
    printList(head);

    int arr2[] = {1, 2, 3, 4, 5};
    n = sizeof(arr2) / sizeof(arr2[0]);
    k = 3;
    head = createLinkedList(arr2, n);
    head = object.reverseKGroup(head, k);
    return 0;
}