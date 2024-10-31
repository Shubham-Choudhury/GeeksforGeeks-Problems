// Link: https://www.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *getNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct Node *createDLL(vector<int> arr)
{
    struct Node *head = getNode(arr[0]);
    struct Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        struct Node *temp = getNode(arr[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    return head;
}

class Solution
{
public:
    Node *sortedInsert(Node *head, int x)
    {
        Node *insert = new Node();
        insert->data = x;
        insert->next = nullptr;
        insert->prev = nullptr;

        if (x <= head->data)
        {
            insert->next = head;
            head->prev = insert;
            return insert;
        }

        Node *curr = head->next;
        Node *prev = head;

        while (curr != nullptr && x > curr->data)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = insert;
        insert->prev = prev;

        if (curr != nullptr)
        {
            curr->prev = insert;
            insert->next = curr;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 5, 8, 10, 12};
    struct Node *head = createDLL(arr);
    int x = 9;
    head = obj.sortedInsert(head, x);
    printList(head);

    arr = {1, 4, 10, 11};
    head = createDLL(arr);
    x = 15;
    head = obj.sortedInsert(head, x);
    printList(head);
    return 0;
}