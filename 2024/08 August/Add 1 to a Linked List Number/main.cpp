// Link: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

Node *createLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

class Solution
{
public:
    Node *addOne(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        Node *temp = head;
        int carry = 1;

        while (temp != NULL)
        {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp = temp->next;
        }

        if (carry > 0)
        {
            prev->next = new Node(carry);
        }

        curr = head;
        prev = NULL;
        next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 5, 6};
    Node *head = createLinkedList(arr);
    head = obj.addOne(head);
    printList(head);

    arr = {1, 2, 3};
    head = createLinkedList(arr);
    head = obj.addOne(head);
    printList(head);
    return 0;
}