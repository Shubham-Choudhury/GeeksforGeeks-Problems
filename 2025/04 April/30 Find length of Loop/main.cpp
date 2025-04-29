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

Node *createLoopedList(vector<int> arr, int pos)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    int n = arr.size();
    if (n == 0)
        return NULL;
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    loopHere(head, tail, pos);
    return head;
}

class Solution
{
public:
    int loopsize(Node *slow, Node *fast)
    {
        int count = 1;
        fast = fast->next;

        while (fast != slow)
        {
            fast = fast->next;
            count++;
        }
        return count;
    }

    int countNodesinLoop(Node *head)
    {
        Node *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return loopsize(slow, fast);
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {25, 14, 19, 33, 10, 21, 39, 90, 59, 45};
    int pos = 4;
    Node *head = createLoopedList(arr, pos);
    cout << "Loop Length: " << obj.countNodesinLoop(head) << endl;

    arr = {0, 1, 2, 3};
    pos = 0;
    head = createLoopedList(arr, pos);
    cout << "Loop Length: " << obj.countNodesinLoop(head) << endl;
    return 0;
}
