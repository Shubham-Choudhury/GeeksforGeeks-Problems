// Link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
    {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res)
{
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

Node *createLinkedList(vector<int> &arr)
{
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        append(&head, &tail, arr[i]);
    }
    return head;
}

class Solution
{
public:
    Node *copyList(Node *head)
    {
        Node *temp = new Node(head->data);
        Node *ans = temp;
        while (head != NULL)
        {
            temp->next = head->next;
            temp->random = head->random;
            temp = temp->next;
            head = head->next;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4};
    Node *head = createLinkedList(arr);
    Node *res = obj.copyList(head);
    bool result = validation(head, res);
    cout << result << endl;
    arr = {1, 3, 5, 9};
    head = createLinkedList(arr);
    res = obj.copyList(head);
    result = validation(head, res);
    cout << result << endl;
    return 0;
}