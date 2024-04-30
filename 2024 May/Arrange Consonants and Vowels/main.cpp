// Link: https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
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

void append(struct Node **headRef, char data)
{
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

class Solution
{
public:
    struct Node *arrangeCV(Node *head)
    {
        struct Node *ans = new Node('z');
        Node *temp = head, *next = ans;
        while (temp)
        {
            if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
            {
                Node *n = new Node(temp->data);
                next->next = n;
                next = next->next;
            }
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            if (temp->data != 'a' && temp->data != 'e' && temp->data != 'i' && temp->data != 'o' && temp->data != 'u')
            {
                Node *n = new Node(temp->data);
                next->next = n;
                next = next->next;
            }
            temp = temp->next;
        }
        return ans->next;
    }
};

int main()
{
    Solution obj;
    vector<char> values = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    Node *head = new Node(values[0]);
    for (int i = 1; i < values.size(); i++)
        append(&head, values[i]);
    Node *result = obj.arrangeCV(head);
    printlist(result);

    values = {'a', 'b', 'a', 'b', 'd', 'e', 'e', 'b'};
    head = new Node(values[0]);
    for (int i = 1; i < values.size(); i++)
        append(&head, values[i]);
    result = obj.arrangeCV(head);
    printlist(result);
}