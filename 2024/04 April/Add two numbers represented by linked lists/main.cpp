// Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include <bits/stdc++.h>
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

struct Node *buildList(vector<int> &values)
{

    Node *head = new Node(values[0]);
    Node *tail = head;

    for (int i = 1; i < values.size(); i++)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *rev(Node *head)
    {
        Node *cur = head;
        Node *prev = NULL;
        Node *after = NULL;

        while (cur != NULL)
        {
            after = cur->next;
            cur->next = prev;
            prev = cur;
            cur = after;
        }

        return prev;
    }

    Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        if (num1 == NULL)
            return num2;

        if (num2 == NULL)
            return num1;

        Node *temp = new Node(-1);
        Node *cur = temp;

        Node *l1 = rev(num1);
        Node *l2 = rev(num2);

        int carry = 0;

        while ((l1 != NULL || l2 != NULL) || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;

            Node *node = new Node(sum % 10);
            cur->next = node;
            cur = cur->next;
        }

        temp = rev(temp->next);
        while (temp->data == 0 && temp->next != NULL)
            temp = temp->next;

        return temp;
    }
};

int main()
{
    Solution obj;
    vector<int> values1 = {4, 5};
    vector<int> values2 = {3, 4, 5};
    Node *num1 = buildList(values1);
    Node *num2 = buildList(values2);
    Node *res = obj.addTwoLists(num1, num2);
    printList(res);

    values1 = {0, 0, 6, 3};
    values2 = {0, 7};
    num1 = buildList(values1);
    num2 = buildList(values2);
    res = obj.addTwoLists(num1, num2);
    printList(res);

    return 0;
}