// Link: https://www.geeksforgeeks.org/problems/make-binary-tree/1

#include <iostream>
#include <queue>
using namespace std;

/* Link list Node */
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

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r)
{
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty())
    {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head)
{
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

void createLinkedList(Node *&head, vector<int> elements)
{
    for (int i = 0; i < elements.size(); i++)
    {
        push(&head, elements[i]);
    }
}

void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void convert(Node *head, TreeNode *&root)
{
    queue<TreeNode *> q;

    if (head == NULL)
    {
        root = NULL;
        return;
    }

    root = new TreeNode(head->data);
    q.push(root);

    head = head->next;

    while (head)
    {
        TreeNode *k = q.front();
        q.pop();

        TreeNode *leftT = NULL;
        TreeNode *rightT = NULL;
        leftT = new TreeNode(head->data);

        q.push(leftT);
        head = head->next;
        if (head)
        {
            rightT = new TreeNode(head->data);
            q.push(rightT);
            head = head->next;
        }

        k->left = leftT;
        k->right = rightT;
    }
}

int main()
{
    vector<int> elements = {1, 2, 3, 4, 5};
    Node *head = NULL;
    createLinkedList(head, elements);
    TreeNode *root = NULL;
    convert(head, *&root);
    printTree(root);
    cout << endl;

    elements = {5, 4, 3, 2, 1};
    head = NULL;
    createLinkedList(head, elements);
    root = NULL;
    convert(head, *&root);
    printTree(root);
}