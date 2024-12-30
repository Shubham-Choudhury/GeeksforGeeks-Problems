// Link: https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

Node *BuildLinkedList(vector<int> &arr)
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
    Node *rotate(Node *head, int k)
    {
        int count = 1;
        Node *temp = head;
        for (int i = 1; i < k; i++)
        {
            temp = temp->next;
        }
        Node *thead = temp->next;
        Node *ans = temp->next;
        temp->next = NULL;
        while (thead != NULL && thead->next != NULL)
        {
            thead = thead->next;
        }

        if (thead == NULL)
        {
            return head;
        }
        else
        {
            thead->next = head;
            return ans;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 4, 7, 8, 9};
    Node *head = BuildLinkedList(arr);
    printList(head);
    int k = 3;
    Node *newHead = obj.rotate(head, k);
    printList(newHead);

    arr = {1, 2, 3, 4, 5, 6, 7, 8};
    head = BuildLinkedList(arr);
    printList(head);
    k = 4;
    newHead = obj.rotate(head, k);
    printList(newHead);
    return 0;
}