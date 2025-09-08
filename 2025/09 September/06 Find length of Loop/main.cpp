// Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *createLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}

Node *createLoop(Node *head, int x)
{
    if (x == 0)
        return head;

    Node *curr = head;
    Node *last = head;
    Node *joinNode = NULL;

    int count = 1;
    while (last->next != NULL)
    {
        if (count == x)
            joinNode = curr;
        curr = curr->next;
        last = last->next;
        count++;
    }
    last->next = joinNode;

    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    unordered_set<Node *> visited;

    while (temp != NULL && visited.find(temp) == visited.end())
    {
        cout << temp->data << " -> ";
        visited.insert(temp);
        temp = temp->next;
    }
    if (temp != NULL)
    {
        cout << "... (loop starts again at node with data: " << temp->data << ")\n";
    }
    else
    {
        cout << "NULL\n";
    }
}

class Solution
{
public:
    int countNodes(Node *node)
    {
        int res = 1;
        Node *curr = node;
        while (curr->next != node)
        {
            res++;
            curr = curr->next;
        }
        return res;
    }

    int lengthOfLoop(Node *head)
    {
        Node *slow = head, *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return countNodes(slow);
        }

        return 0;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = createLinkedList(arr);
    int pos = 2;
    head = createLoop(head, pos);
    cout << "Linked List:" << endl;
    printLinkedList(head);
    int length = sol.lengthOfLoop(head);
    cout << "Length of Loop: " << length << endl
         << endl;

    arr = {25, 14, 19, 33, 10};
    head = createLinkedList(arr);
    pos = 3;
    head = createLoop(head, pos);
    cout << "Linked List:" << endl;
    printLinkedList(head);
    length = sol.lengthOfLoop(head);
    cout << "Length of Loop: " << length << endl
         << endl;

    arr = {1, 2, 3, 4, 5};
    head = createLinkedList(arr);
    pos = 0;
    head = createLoop(head, pos);
    cout << "Linked List:" << endl;
    printLinkedList(head);
    length = sol.lengthOfLoop(head);
    cout << "Length of Loop: " << length << endl
         << endl;

    return 0;
}