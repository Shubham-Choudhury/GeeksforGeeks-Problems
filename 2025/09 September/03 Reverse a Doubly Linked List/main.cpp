// Link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node *createLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }

    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *prevNode = NULL;
        Node *currNode = head;

        while (currNode != nullptr)
        {
            prevNode = currNode->prev;
            currNode->prev = currNode->next;
            currNode->next = prevNode;
            currNode = currNode->prev;
        }

        return prevNode->prev;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 4, 5};
    Node *head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.reverse(head);
    cout << "Reversed Linked List: " << endl;
    printLinkedList(head);

    arr = {75, 122, 59, 196};
    head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.reverse(head);
    cout << "Reversed Linked List: " << endl;
    printLinkedList(head);

    return 0;
}