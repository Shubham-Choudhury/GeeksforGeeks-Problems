// Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

Node *createLinkedList(vector<int> arr)
{
    Node *root = new Node(arr[0]);
    Node *temp = root;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return root;
}

class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push({arr[i]->data, arr[i]});
        }
        Node *head = NULL;
        Node *temp;
        while (!pq.empty())
        {
            Node *init = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if (init->next != NULL)
            {
                pq.push({init->next->data, init->next});
            }
            if (head == NULL)
            {
                head = new Node(val);
                temp = head;
            }
            else
            {
                Node *naya = new Node(val);
                temp->next = naya;
                temp = naya;
            }
        }
        return head;
    }
};

int main()
{
    Solution object;
    vector<vector<int>> list = {
        {1, 2, 3},
        {4, 5},
        {5, 6},
        {7, 8}};
    vector<Node *> arr;
    for (auto l : list)
    {
        arr.push_back(createLinkedList(l));
    }
    Node *head = object.mergeKLists(arr);
    printList(head);
    cout << endl;

    list = {
        {1, 3},
        {8},
        {4, 5, 6}};
    arr.clear();
    for (auto l : list)
    {
        arr.push_back(createLinkedList(l));
    }
    head = object.mergeKLists(arr);
    printList(head);
    return 0;
}