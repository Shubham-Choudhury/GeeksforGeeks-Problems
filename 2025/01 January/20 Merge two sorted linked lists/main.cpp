// Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

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

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data)
{
    Node *new_node = new Node(data);
    if (!head || head->data >= data)
    {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

Node *createLinkedList(int arr[], int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = insertSorted(head, arr[i]);
    }
    return head;
}

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        Node *head = (head1->data <= head2->data) ? head1 : head2;
        Node *tail = head;
        Node *a = head1;
        Node *b = head2;
        (head1->data <= head2->data) ? a = a->next : b = b->next;
        while (a != NULL && b != NULL)
        {
            tail->next = (a->data <= b->data) ? a : b;
            (a->data <= b->data) ? a = a->next : b = b->next;
            tail = tail->next;
        }
        tail->next = (b == NULL) ? a : b;
        return head;
    }
};

int main()
{
    Solution object;
    int arr11[] = {5, 10, 15, 40};
    int arr12[] = {2, 3, 20};
    int n1 = sizeof(arr11) / sizeof(arr11[0]);
    int n2 = sizeof(arr12) / sizeof(arr12[0]);
    Node *head1 = createLinkedList(arr11, n1);
    Node *head2 = createLinkedList(arr12, n2);
    Node *merge = object.sortedMerge(head1, head2);
    printList(merge);

    int arr21[] = {1, 1};
    int arr22[] = {2, 4};
    n1 = sizeof(arr21) / sizeof(arr21[0]);
    n2 = sizeof(arr22) / sizeof(arr22[0]);
    head1 = createLinkedList(arr21, n1);
    head2 = createLinkedList(arr22, n2);
    merge = object.sortedMerge(head1, head2);
    printList(merge);

    return 0;
}