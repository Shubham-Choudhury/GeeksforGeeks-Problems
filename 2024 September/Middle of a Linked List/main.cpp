// Link: https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

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

Node *buidTree(vector<int> &arr)
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

class Solution
{
public:
    int getMiddle(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = buidTree(arr);
    cout << obj.getMiddle(head) << endl;

    arr = {2, 4, 6, 7, 5, 1};
    head = buidTree(arr);
    cout << obj.getMiddle(head) << endl;
    return 0;
}