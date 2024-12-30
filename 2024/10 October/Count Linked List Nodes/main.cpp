// Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1

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
    int getCount(struct Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    struct Node *head = createLinkedList(arr);
    cout << obj.getCount(head) << endl;

    arr = {2, 4, 6, 7, 5, 1, 0};
    head = createLinkedList(arr);
    cout << obj.getCount(head) << endl;
    return 0;
}