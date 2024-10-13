// Link: https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1

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

struct Node *createLinkedList(vector<int> &arr)
{
    struct Node *head = new Node(arr[0]);
    struct Node *tail = head;
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
    void deleteAlt(struct Node *head)
    {
        Node *curr = head;
        while (curr && curr->next)
        {
            curr->next = curr->next->next;
            curr = curr->next;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    struct Node *head = createLinkedList(arr);
    obj.deleteAlt(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    arr = {99, 59, 42, 20};
    head = createLinkedList(arr);
    obj.deleteAlt(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}