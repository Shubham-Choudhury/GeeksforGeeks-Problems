// Link: https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

#include <iostream>
#include <vector>
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

// Function to print nodes in a given circular linked list
void printList(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        cout << "empty" << endl;
    }
    cout << endl;
}

struct Node *createCirculerLinkedList(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    return head;
}

class Solution
{
public:
    // Function to reverse a circular linked list
    Node *reverse(Node *head)
    {
        if (head == nullptr or head->next == head)
        {
            return head;
        }
        Node *curr = head, *prev = nullptr;
        do
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);
        curr->next = prev;
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node *deleteNode(Node *head, int key)
    {
        if (head == nullptr || head->next == head && head->data == key)
            return nullptr;
        if (head->data == key)
        {
            head->data = head->next->data;
            head->next = head->next->next;
            return head;
        }
        Node *node = head->next;
        Node *prev = head;
        while (node != head)
        {
            if (node->data == key)
            {
                prev->next = node->next;
                return head;
            }
            prev = node;
            node = node->next;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 5, 7, 8, 10};
    Node *head = createCirculerLinkedList(arr);
    head = obj.reverse(head);
    printList(head);
    head = obj.deleteNode(head, 7);
    printList(head);

    arr = {1, 7, 8, 10};
    head = createCirculerLinkedList(arr);
    head = obj.reverse(head);
    printList(head);
    head = obj.deleteNode(head, 1);
    printList(head);
    return 0;
}