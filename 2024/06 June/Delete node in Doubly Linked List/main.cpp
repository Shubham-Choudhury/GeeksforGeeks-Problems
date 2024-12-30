// Link: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void createLinkedList(Node **head, vector<int> elements)
{
    Node *temp = *head;
    for (int i = 0; i < elements.size(); i++)
    {
        Node *newNode = new Node(elements[i]);
        if (*head == NULL)
        {
            *head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        if (x == 1)
        {
            head = head->next;
            head->prev = NULL;
            return head;
        }
        int cnt = 1;
        Node *temp = head;
        while (cnt < x - 1)
        {
            temp = temp->next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main()
{
    Solution obj;
    Node *head = NULL;
    vector<int> elements = {1, 3, 4};
    createLinkedList(&head, elements);
    int x = 3;
    head = obj.deleteNode(head, x);
    printList(head);

    head = NULL;
    elements = {1, 5, 2, 9};
    createLinkedList(&head, elements);
    x = 1;
    head = obj.deleteNode(head, x);
    printList(head);
    return 0;
}