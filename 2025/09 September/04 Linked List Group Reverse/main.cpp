// Link: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

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
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
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
    Node *reverseKGroup(Node *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }

        Node *curr = head;
        Node *newHead = nullptr;
        Node *tail = nullptr;

        while (curr != nullptr)
        {
            Node *groupHead = curr;
            Node *prev = nullptr;
            Node *nextNode = nullptr;
            int count = 0;

            while (curr != nullptr && count < k)
            {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }

            if (newHead == nullptr)
            {
                newHead = prev;
            }

            if (tail != nullptr)
            {
                tail->next = prev;
            }

            tail = groupHead;
        }

        return newHead;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;
    Node *head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.reverseKGroup(head, k);
    cout << "Reversed Linked List in groups of " << k << ": " << endl;
    printLinkedList(head);
    cout << endl;

    arr = {1, 2, 3, 4, 5, 6};
    k = 4;
    head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.reverseKGroup(head, k);
    cout << "Reversed Linked List in groups of " << k << ": " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}