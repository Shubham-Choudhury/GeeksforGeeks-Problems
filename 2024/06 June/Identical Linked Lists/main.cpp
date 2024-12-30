// Link: https://www.geeksforgeeks.org/problems/identical-linked-lists/1

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

bool areIdentical(struct Node *head1, struct Node *head2);
void createLinkedList(struct Node **head, vector<int> elements);

void createLinkedList(struct Node **head, vector<int> elements)
{
    struct Node *temp = *head;
    for (int i = 0; i < elements.size(); i++)
    {
        if (*head == NULL)
        {
            *head = new Node(elements[i]);
            temp = *head;
        }
        else
        {
            temp->next = new Node(elements[i]);
            temp = temp->next;
        }
    }
}

bool areIdentical(struct Node *head1, struct Node *head2)
{
    while (head1 && head2)
    {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 || head2)
        return false;
    return true;
}

int main()
{
    struct Node *head1 = NULL;
    vector<int> elements = {1, 2, 3, 4, 5, 6};
    createLinkedList(&head1, elements);
    struct Node *head2 = NULL;
    elements = {99, 59, 42, 20};
    createLinkedList(&head2, elements);
    cout << areIdentical(head1, head2) << endl;

    head1 = NULL;
    elements = {1, 2, 3, 4, 5};
    createLinkedList(&head1, elements);
    head2 = NULL;
    elements = {1, 2, 3, 4, 5};
    createLinkedList(&head2, elements);
    cout << areIdentical(head1, head2) << endl;
    return 0;
}