// Link: https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
} *head;

Node *findNode(Node *head, int search_for)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}

void insert(Node **head_ref, int new_data)
{
    if (*head_ref == NULL)
    {
        *head_ref = new Node(new_data);
    }
    else
    {
        Node *temp = new Node(new_data);
        temp->next = *head_ref;
        *head_ref = temp;
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class Solution
{
public:
    void deleteNode(Node *del_node)
    {
        Node *temp = del_node->next;
        del_node->data = temp->data;
        del_node->next = temp->next;
        delete temp;
    }
};

int main()
{
    Solution obj;
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    obj.deleteNode(findNode(head, 1));
    printList(head);

    head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 30);
    obj.deleteNode(findNode(head, 20));
    printList(head);

    return 0;
}