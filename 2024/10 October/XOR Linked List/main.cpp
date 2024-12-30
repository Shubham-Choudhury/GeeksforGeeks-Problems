// Link: https://www.geeksforgeeks.org/problems/xor-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *npx;

    Node(int x)
    {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b)
{
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    temp->npx = head;
    if (head->npx != NULL)
    {
        head->npx = XOR(head->npx, temp);
    }
    else
    {
        head->npx = temp;
    }

    head = temp;
    return head;
}

vector<int> getList(struct Node *head)
{
    vector<int> ans;
    struct Node *prev = NULL;
    struct Node *temp = head;
    while (temp)
    {
        struct Node *t = temp;
        ans.push_back(temp->data);
        if (prev)
        {
            temp = XOR(temp->npx, prev);
        }
        else
        {
            temp = temp->npx;
        }
        prev = t;
    }

    return ans;
}

int main()
{
    vector<int> arr = {9, 5, 4, 7, 3, 10};
    struct Node *head = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        head = insert(head, arr[i]);
    }
    vector<int> res = getList(head);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    arr = {58, 96, 31};
    head = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        head = insert(head, arr[i]);
    }
    res = getList(head);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}