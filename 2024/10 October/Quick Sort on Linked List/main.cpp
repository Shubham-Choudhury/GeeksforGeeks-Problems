// Link: https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

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

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node *&head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Partitions the list taking the last element as the pivot
struct Node *partition(struct Node *head, struct Node *end, struct Node *&newHead,
                       struct Node *&newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == NULL)
                newHead = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        { // If cur node is greater than pivot
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, pivot becomes the
    // head
    if (newHead == NULL)
        newHead = pivot;

    // Update newEnd to the current last node
    newEnd = tail;

    // Return the pivot node
    return pivot;
}

struct Node *createLinkedList(vector<int> &arr)
{
    struct Node *head = NULL;
    for (int i = arr.size() - 1; i >= 0; i--)
        push(head, arr[i]);
    return head;
}

class Solution
{
    vector<Node *> getPivot(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return {head, NULL};

        Node *less = new Node(-1);
        Node *more = new Node(-1);
        Node *mark1 = less;
        Node *mark2 = more;

        int val = head->data;

        Node *temp = head->next;
        while (temp)
        {
            if (temp->data <= val)
            {
                less->next = temp;
                less = temp;
            }
            else
            {
                more->next = temp;
                more = temp;
            }
            temp = temp->next;
        }
        head->next = NULL;
        less->next = NULL;
        more->next = NULL;

        less = mark1->next;
        more = mark2->next;

        delete mark1;
        delete mark2;

        return {less, head, more};
    }

public:
    struct Node *quickSort(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        auto pivot = getPivot(head);
        Node *first = quickSort(pivot[0]);
        Node *second = quickSort(pivot[2]);

        head->next = second;

        if (first)
        {
            Node *temp = first;
            while (temp->next)
                temp = temp->next;
            temp->next = head;
            return first;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 9, 3, 8};
    Node *head = createLinkedList(arr);
    head = obj.quickSort(head);
    printList(head);

    arr = {1, 6, 2};
    head = createLinkedList(arr);
    head = obj.quickSort(head);
    printList(head);
    return 0;
}