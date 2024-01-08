// Link: https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Solution
{
public:
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        Node *prev = NULL;
        while (node1 != NULL && node2 != NULL)
        {
            int data;
            if (node1->data < node2->data)
            {
                data = node1->data;
                node1 = node1->next;
            }
            else
            {
                data = node2->data;
                node2 = node2->next;
            }
            Node *nlist = new Node;
            nlist->data = data;
            nlist->next = prev;
            prev = nlist;
        }
        while (node1 != NULL)
        {
            int data;
            data = node1->data;
            node1 = node1->next;

            Node *nlist = new Node;
            nlist->data = data;
            nlist->next = prev;
            prev = nlist;
        }
        while (node2 != NULL)
        {
            int data;

            data = node2->data;
            node2 = node2->next;

            Node *nlist = new Node;
            nlist->data = data;
            nlist->next = prev;
            prev = nlist;
        }
        return prev;
    }
};

int main()
{
    Solution obj;
    int N = 2;
    int M = 2;
    Node *list1 = new Node;
    list1->data = 1;
    list1->next = new Node;
    list1->next->data = 3;
    list1->next->next = NULL;
    Node *list2 = new Node;
    list2->data = 2;
    list2->next = new Node;
    list2->next->data = 4;
    list2->next->next = NULL;
    Node *result = obj.mergeResult(list1, list2);
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    N = 4;
    M = 3;
    list1 = new Node;
    list1->data = 5;
    list1->next = new Node;
    list1->next->data = 10;
    list1->next->next = new Node;
    list1->next->next->data = 15;
    list1->next->next->next = new Node;
    list1->next->next->next->data = 40;
    list1->next->next->next->next = NULL;
    list2 = new Node;
    list2->data = 2;
    list2->next = new Node;
    list2->next->data = 3;
    list2->next->next = new Node;
    list2->next->next->data = 20;
    list2->next->next->next = NULL;
    result = obj.mergeResult(list1, list2);
    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}