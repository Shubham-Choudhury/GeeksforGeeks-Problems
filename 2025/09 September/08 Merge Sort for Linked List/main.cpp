// Link: https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

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
        next = nullptr;
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
    Node *split(Node *head)
    {
        Node *fast = head;
        Node *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if (fast != nullptr)
            {
                slow = slow->next;
            }
        }

        Node *temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    Node *merge(Node *first, Node *second)
    {
        if (first == nullptr)
            return second;
        if (second == nullptr)
            return first;

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            return second;
        }
    }

    Node *mergeSort(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *second = split(head);

        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head, second);
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {40, 20, 60, 10, 50, 30};
    Node *head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.mergeSort(head);
    cout << "Sorted Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    arr = {9, 5, 2, 8};
    head = createLinkedList(arr);
    cout << "Original Linked List: " << endl;
    printLinkedList(head);
    head = sol.mergeSort(head);
    cout << "Sorted Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}