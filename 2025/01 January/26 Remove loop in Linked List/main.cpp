// Link: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int> &myMap)
{

    while (head)
    {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
}

Node *createLinkedList(int arr[], int n)
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        Node *node = new Node(arr[i]);

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

Node *getTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail; // Return the tail node
}

class Solution
{
public:
    void removeLoop(Node *head)
    {
        if (head == NULL)
            return;
        Node *slow = head;
        Node *fast = head;
        Node *ptr = head;
        Node *pre = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
            if (slow == fast)
            {
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    pre = slow;
                    slow = slow->next;
                }
                pre->next = NULL;
                return;
            }
        }
    }
};

int main()
{
    Solution object;
    int arr1[] = {1, 3, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *head = createLinkedList(arr1, n);
    Node *tail = getTail(head);
    loopHere(head, tail, 2);
    object.removeLoop(head);
    cout << boolalpha << isLoop(head) << endl;

    int arr2[] = {1, 8, 3, 4};
    n = sizeof(arr2) / sizeof(arr2[0]);
    head = createLinkedList(arr2, n);
    tail = getTail(head);
    loopHere(head, tail, 0);
    object.removeLoop(head);
    cout << boolalpha << isLoop(head) << endl;

    int arr3[] = {1, 2, 3, 4};
    n = sizeof(arr3) / sizeof(arr3[0]);
    head = createLinkedList(arr3, n);
    tail = getTail(head);
    loopHere(head, tail, 1);
    object.removeLoop(head);
    cout << boolalpha << isLoop(head) << endl;
    return 0;
}