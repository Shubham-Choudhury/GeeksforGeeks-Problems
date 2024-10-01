// Link: https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

#include <iostream>
#include <vector>
using namespace std;

/* Linked list Node */
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

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r)
{
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node **head_ref, int new_data)
{
    /* allocate Node */
    struct Node *new_Node = newNode(new_data);

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

struct Node *createLinkedList(vector<int> &arr)
{
    struct Node *head = NULL;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        push(&head, arr[i]);
    }
    return head;
}

class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        long long num1 = 0, num2 = 0;
        long long mod = 1000000007;
        Node *temp1 = first;
        Node *temp2 = second;
        while (temp1)
        {
            num1 = (num1 * 10) % mod + (temp1->data) % mod;
            temp1 = temp1->next;
        }
        while (temp2)
        {
            num2 = (num2 * 10) % mod + (temp2->data) % mod;
            temp2 = temp2->next;
        }
        long long ans = (num1 * num2) % mod;
        return ans % mod;
    }
};

int main()
{
    solution obj;
    vector<int> arr1 = {3, 2};
    vector<int> arr2 = {2};
    Node *head1 = createLinkedList(arr1);
    Node *head2 = createLinkedList(arr2);
    cout << obj.multiplyTwoLists(head1, head2) << endl;

    arr1 = {1, 0, 0};
    arr2 = {1, 0};
    head1 = createLinkedList(arr1);
    head2 = createLinkedList(arr2);
    cout << obj.multiplyTwoLists(head1, head2) << endl;

    return 0;
}