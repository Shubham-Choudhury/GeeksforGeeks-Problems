// Link: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

#include <iostream>
#include <algorithm>
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

Node *createSortedCircularLinkedList(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return NULL;
    sort(arr.begin(), arr.end());

    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
    return head;
}

void printCircularLinkedList(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            newNode->next = newNode;
            head = newNode;
            return head;
        }

        Node *curr = head;
        Node *nextToCurr = head->next;

        if (data <= head->data)
        {
            Node *lastNode = head;
            while (lastNode->next != head)
            {
                lastNode = lastNode->next;
            }
            newNode->next = head;
            lastNode->next = newNode;
            head = newNode;
            return head;
        }

        while (curr->next != head)
        {
            if (curr->data < data && nextToCurr->data >= data)
            {
                newNode->next = curr->next;
                curr->next = newNode;
                return head;
            }
            else
            {
                curr = curr->next;
                nextToCurr = nextToCurr->next;
            }
        }
        newNode->next = head;
        curr->next = newNode;
        return head;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {1, 2, 4};
    Node *head = createSortedCircularLinkedList(arr);
    cout << "Original Circular Linked List: ";
    printCircularLinkedList(head);
    int data = 2;
    head = solution.sortedInsert(head, data);
    cout << "Circular Linked List after inserting " << data << ": ";
    printCircularLinkedList(head);

    arr = {1, 7, 9, 4};
    head = createSortedCircularLinkedList(arr);
    cout << "Original Circular Linked List: ";
    printCircularLinkedList(head);
    data = 5;
    head = solution.sortedInsert(head, data);
    cout << "Circular Linked List after inserting " << data << ": ";
    printCircularLinkedList(head);
    return 0;
}