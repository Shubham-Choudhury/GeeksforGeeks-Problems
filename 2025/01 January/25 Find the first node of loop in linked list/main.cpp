// Link: https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

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

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

Node *createLinkedList(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}

class Solution
{
public:
    Node *findFirstNode(Node *head)
    {
        Node *slowptr = head;
        Node *fastptr = head;
        while (fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if (slowptr == fastptr)
            {
                fastptr = head;
                if (fastptr != NULL && slowptr != NULL)
                {
                    while (slowptr != fastptr)
                    {
                        slowptr = slowptr->next;
                        fastptr = fastptr->next;
                    }
                    return slowptr;
                }
            }
        }
        return NULL;
    }
};

int main()
{
    Solution solution;
    int arr1[] = {1, 3, 2, 4, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *head = createLinkedList(arr1, n);
    loopHere(head, head->next, 2);
    Node *result = solution.findFirstNode(head);
    if (result != NULL)
        cout << result->data << "\n";
    else
        cout << "No Loop" << "\n";
    return 0;
}