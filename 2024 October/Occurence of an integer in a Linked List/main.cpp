// Link: https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1

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
    int count(struct Node *head, int key)
    {
        int res = 0;

        while (head != nullptr)
        {
            if (head->data == key)
            {
                res++;
            }
            head = head->next;
        }

        return res;
    }
};

int main()
{
    Solution ob;
    vector<int> arr = {1, 2, 1, 2, 1, 3, 1};
    struct Node *head = createLinkedList(arr);
    int key = 1;
    cout << ob.count(head, key) << endl;

    arr = {1, 2, 1, 2, 1};
    head = createLinkedList(arr);
    key = 3;
    cout << ob.count(head, key) << endl;
    return 0;
}