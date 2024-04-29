// Link: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

#include <bits/stdc++.h>
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

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        if (K == 1)
            return NULL;
        Node *curr = head;
        int cnt = 1;
        while (curr != NULL)
        {
            cnt++;
            if (cnt == K && curr->next != NULL)
            {
                curr->next = curr->next->next;
                cnt = 1;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 2;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < arr.size(); i++)
        append(&head, &tail, arr[i]);
    Node *res = obj.deleteK(head, k);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    cout << endl;

    arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    k = 3;
    head = NULL, tail = NULL;
    for (int i = 0; i < arr.size(); i++)
        append(&head, &tail, arr[i]);
    res = obj.deleteK(head, k);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}