// Link: https://www.geeksforgeeks.org/problems/find-length-of-loop/1

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

Node *createLinkedList(vector<int> &arr)
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

Node *getTail(struct Node *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

class Solution
{
private:
    int countLoopLength(Node *loopNode)
    {
        int count = 1;
        Node *temp = loopNode;
        while (temp->next != loopNode)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    int countNodesinLoop(struct Node *head)
    {
        if (!head || !head->next)
            return 0;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return countLoopLength(slow);
            }
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {25, 14, 19, 33, 10, 21, 39, 90, 58, 45};
    int pos = 4;
    Node *head = createLinkedList(arr);
    Node *tail = getTail(head);
    loopHere(head, tail, pos);
    cout << obj.countNodesinLoop(head) << endl;

    arr = {5, 4};
    pos = 0;
    head = createLinkedList(arr);
    tail = getTail(head);
    loopHere(head, tail, pos);
    cout << obj.countNodesinLoop(head) << endl;
    return 0;
}