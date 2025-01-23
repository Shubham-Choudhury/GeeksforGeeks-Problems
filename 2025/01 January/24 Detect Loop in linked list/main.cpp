// Link: https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
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
    bool detectLoop(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        Node *rabbit = head->next->next, *turtle = head;
        while (rabbit != turtle)
        {
            if (rabbit == nullptr || rabbit->next == nullptr || rabbit->next->next == nullptr)
            {
                return false;
            }
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }

        return true;
    }
};

int main()
{
    Solution object;
    int arr1[] = {1, 3, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    Node *head = createLinkedList(arr1, n);
    int pos = 2;
    loopHere(head, head->next, pos);
    cout << boolalpha << object.detectLoop(head) << endl;

    int arr2[] = {1, 8, 3, 4};
    n = sizeof(arr2) / sizeof(arr2[0]);
    head = createLinkedList(arr2, n);
    pos = 0;
    loopHere(head, head->next->next, pos);
    cout << boolalpha << object.detectLoop(head) << endl;

    int arr3[] = {1, 2, 3, 4};
    n = sizeof(arr3) / sizeof(arr3[0]);
    head = createLinkedList(arr3, n);
    pos = 1;
    loopHere(head, head->next->next, pos);
    cout << boolalpha << object.detectLoop(head) << endl;
    return 0;
}