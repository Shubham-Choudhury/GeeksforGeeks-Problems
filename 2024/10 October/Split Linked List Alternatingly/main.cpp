// Link: https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

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

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *createLinkedList(vector<int> &arr)
{
    struct Node *head = new Node(arr[0]);
    struct Node *temp = head;
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
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        if (head == NULL)
            return {NULL, NULL};
        Node *odddummy = new Node(0);
        Node *evendummy = new Node(0);
        Node *odd = odddummy;
        Node *even = evendummy;
        Node *curr = head;
        bool o = true;
        while (curr != NULL)
        {
            if (o)
            {
                odd->next = curr;
                odd = odd->next;
            }
            else
            {
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            o = !o;
        }
        odd->next = NULL;
        even->next = NULL;
        return {odddummy->next, evendummy->next};
    }
};

int main()
{
    vector<int> arr = {0, 1, 0, 1, 0, 1};
    struct Node *head = createLinkedList(arr);
    Solution ob;
    vector<Node *> ans = ob.alternatingSplitList(head);
    printList(ans[0]);
    printList(ans[1]);

    arr = {2, 5, 8, 9, 6};
    head = createLinkedList(arr);
    ans = ob.alternatingSplitList(head);
    printList(ans[0]);
    printList(ans[1]);
    return 0;
}