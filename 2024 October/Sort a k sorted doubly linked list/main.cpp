// Link: https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void push(DLLNode **headRef, DLLNode **tailRef, int new_data)
{
    DLLNode *newNode = new DLLNode(new_data);

    if ((*tailRef) == NULL)
    {
        // If the list is empty, both head and tail point to the new node
        (*headRef) = newNode;
        (*tailRef) = newNode;
    }
    else
    {
        // Insert the new node at the end and update the tail
        newNode->prev = (*tailRef);
        (*tailRef)->next = newNode;
        (*tailRef) = newNode;
    }
}

void printList(DLLNode *head)
{
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

DLLNode *createDoublyLinkedList(vector<int> &arr)
{
    DLLNode *head = NULL;
    DLLNode *tail = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        push(&head, &tail, arr[i]);
    }
    return head;
}

class Solution
{
public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        if (!head)
            return head;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        DLLNode *newHead = NULL, *sortedTail = NULL, *current = head;

        for (int i = 0; i <= k && current; ++i)
        {
            minHeap.push(current->data);
            current = current->next;
        }

        while (!minHeap.empty())
        {
            int minValue = minHeap.top();
            minHeap.pop();

            if (!newHead)
            {
                newHead = new DLLNode(minValue);
                sortedTail = newHead;
            }
            else
            {
                sortedTail->next = new DLLNode(minValue);
                sortedTail->next->prev = sortedTail;
                sortedTail = sortedTail->next;
            }

            if (current)
            {
                minHeap.push(current->data);
                current = current->next;
            }
        }

        return newHead;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    DLLNode *head = createDoublyLinkedList(arr);
    int k = 2;
    DLLNode *sortedHead = obj.sortAKSortedDLL(head, k);
    printList(sortedHead);

    arr = {5, 6, 7, 3, 4, 4};
    head = createDoublyLinkedList(arr);
    k = 3;
    sortedHead = obj.sortAKSortedDLL(head, k);
    printList(sortedHead);

    return 0;
}
