// Link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

Node *createList(vector<int> arr)
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

void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution
{
public:
    Node *segregate(Node *head)
    {
        Node *p = head;
        int count0 = 0, count1 = 0, count2 = 0;
        while (p)
        {
            if (p->data == 1)
                count1++;
            else if (p->data == 2)
                count2++;
            else
                count0++;
            p = p->next;
        }

        p = head;

        while (p)
        {
            if (count0 > 0)
            {
                p->data = 0;
                count0--;
            }
            else if (count1 > 0)
            {
                p->data = 1;
                count1--;
            }
            else
            {
                p->data = 2;
                count2--;
            }
            p = p->next;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 2, 1, 2, 0, 2, 2};
    Node *head = createList(arr);
    cout << "Original List: ";
    printList(head);
    head = obj.segregate(head);
    cout << "Sorted List: ";
    printList(head);

    arr = {2, 2, 0, 1};
    head = createList(arr);
    cout << "Original List: ";
    printList(head);
    head = obj.segregate(head);
    cout << "Sorted List: ";
    printList(head);

    freeList(head);
    return 0;
}