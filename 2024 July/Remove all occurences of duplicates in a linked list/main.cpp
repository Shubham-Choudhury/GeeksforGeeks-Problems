// Link: https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1

#include <iostream>
#include <vector>
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
};
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node *createLinkedList(vector<int> elements)
{
    Node *head = new Node(elements[0]);
    Node *temp = head;
    for (int i = 1; i < elements.size(); i++)
    {
        temp->next = new Node(elements[i]);
        temp = temp->next;
    }
    return head;
}

class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {
        Node *temp = head;
        Node *newHead = NULL;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                Node *temp1 = head;
                if (temp->data == temp->next->data)
                {
                    while (temp->next != NULL && temp->data == temp->next->data)
                    {
                        temp = temp->next;
                    }
                    if (prev == NULL)
                    {
                        temp = temp->next;
                        newHead = temp;
                    }
                    else
                    {
                        prev->next = temp->next;
                        temp = temp->next;
                    }
                }
                else
                {
                    if (prev == NULL)
                    {
                        prev = temp;
                        newHead = temp;
                    }
                    else
                        prev = prev->next;
                    temp = temp->next;
                }
            }
            else
            {
                return newHead;
            }
        }
        return newHead;
    }
};

int main()
{
    Solution obj;
    vector<int> elements = {23, 28, 28, 35, 49, 49, 53, 53};
    Node *head = createLinkedList(elements);
    Node *newHead = obj.removeAllDuplicates(head);
    printList(newHead);

    elements = {11, 11, 11, 11, 75, 75};
    head = createLinkedList(elements);
    newHead = obj.removeAllDuplicates(head);
    printList(newHead);
    return 0;
}